#include "arguments.hpp"
#include "call_frame.hpp"
#include "dispatch.hpp"
#include "object_memory.hpp"
#include "object_utils.hpp"

#include "builtin/class.hpp"
#include "builtin/executable.hpp"
#include "builtin/symbol.hpp"

namespace rubinius {

  void Executable::bootstrap(STATE) {
    GO(executable).set(state->memory()->new_class<Class, Executable>(
          state, G(rubinius), "Executable"));
  }

  Executable* Executable::allocate(STATE, Object* self) {
    Executable* executable =
      state->memory()->new_object<Executable>(state, G(executable));

    Executable::initialize(state, executable, Executable::default_executor);

    if(Class* cls = try_as<Class>(self)) {
      executable->klass(state, cls);
    }

    return executable;
  }

  bool Executable::resolve_primitive(STATE) {
    if(!primitive_->nil_p()) {
      if(Symbol* name = try_as<Symbol>(primitive_)) {
        set_executor(Primitives::resolve_primitive(state, name, &prim_index_));
        return true;
      }
    }

    return false;
  }

  Object* Executable::invoke(STATE, Symbol* name, Module* mod, Object* recv, Array* ary,
                             Object* block, CallFrame* call_frame)
  {
    Arguments args(name, recv, 0, 0);
    args.use_array(ary);
    args.set_block(block);

    return execute(state, call_frame, this, mod, args);
  }

  Object* Executable::default_executor(STATE, CallFrame* call_frame, Executable* exec, Module* mod,
                                       Arguments& args) {
    args.unshift2(state, args.recv(), args.name());
    args.set_recv(exec);

    Dispatch dis(G(sym_call));
    return dis.send(state, call_frame, args);
  }

  void Executable::add_inliner(STATE, ObjectMemory* om, CompiledCode* code) {
    if(!inliners_ || inliners_ == (Inliners*)cNil) {
      inliners_ = new Inliners(state, om);
    }
    inliners_->inliners().push_back(code);

    om->write_barrier(this, code);
  }

  void Executable::clear_inliners(STATE) {
    if(!inliners_ || inliners_ == (Inliners*)cNil) return;
    for(std::vector<CompiledCode*>::const_iterator i = inliners_->inliners().begin();
        i != inliners_->inliners().end();
        ++i) {
      (*i)->machine_code()->deoptimize(state, *i, 0);
    }

    inliners_->inliners().clear();
  }

  void Executable::Info::mark(Object* obj, ObjectMark& mark) {
    auto_mark(obj, mark);
    mark_inliners(obj, mark);
  }

  void Executable::Info::mark_inliners(Object* obj, ObjectMark& mark) {
    Executable* exc = static_cast<Executable*>(obj);
    if(!exc->inliners_ || exc->inliners_ == (Inliners*)cNil) return;

    Inliners* inl = exc->inliners_;
    inl->set_mark();

    // std::cout << "Marking inliners: " << inl->inliners().size() << "\n";

    for(std::vector<CompiledCode*>::iterator i = inl->inliners().begin();
        i != inl->inliners().end();
        ++i) {
      CompiledCode* code = *i;

      if(Object* tmp = mark.call(code)) {
        *i = static_cast<CompiledCode*>(tmp);
        mark.just_set(obj, tmp);
      }
    }
  }

  Inliners::Inliners(STATE, ObjectMemory* om) {
    om->add_code_resource(state, this);
  }

  void Inliners::cleanup(STATE, CodeManager* cm) {
    inliners_.clear();
  }
}
