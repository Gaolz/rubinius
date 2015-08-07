#ifndef RBX_BUILTIN_ALIAS_HPP
#define RBX_BUILTIN_ALIAS_HPP

#include "object_utils.hpp"

#include "builtin/executable.hpp"

namespace rubinius {
  class Alias : public Executable {
  public:
    const static object_type type = AliasType;

  private:
    Symbol* original_name_; // slot
    Module* original_module_; // slot
    Executable* original_exec_; // slot

  public:
    attr_accessor(original_name, Symbol);
    attr_accessor(original_module, Module);
    attr_accessor(original_exec, Executable);

    static Object* executor(STATE, CallFrame* call_frame,
        Executable* exe, Module* mod, Arguments& args);

    static void bootstrap(STATE);
    static void initialize(STATE, Alias* alias) {
      Executable::initialize(state, alias, Alias::executor);

      alias->original_name_ = nil<Symbol>();
      alias->original_module_ = nil<Module>();
      alias->original_exec_ = nil<Executable>();
    }

    static Alias* create(STATE, Symbol* name, Module* mod, Executable* exec);

    class Info : public Executable::Info {
    public:
      BASIC_TYPEINFO(Executable::Info)
    };
  };
}

#endif
