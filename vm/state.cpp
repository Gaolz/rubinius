#include "call_frame.hpp"
#include "helpers.hpp"
#include "object_memory.hpp"
#include "park.hpp"
#include "signal.hpp"
#include "state.hpp"
#include "vm.hpp"

#include "builtin/exception.hpp"
#include "builtin/location.hpp"
#include "builtin/array.hpp"
#include "builtin/fiber.hpp"

namespace rubinius {
  void State::raise_stack_error(CallFrame* call_frame) {
    Class* stack_error = globals().stack_error.get();
    Exception* exc = memory()->new_object<Exception>(this, stack_error);
    exc->locations(this, Location::from_call_stack(this, call_frame));
    vm_->thread_state()->raise_exception(exc);
  }

  bool State::process_async(CallFrame* call_frame) {
    utilities::thread::SpinLock::LockGuard guard(vm_->interrupt_lock());

    vm_->set_call_frame(call_frame);
    vm_->clear_check_local_interrupts();

    Exception* exc = vm_->interrupted_exception_.get();
    if(!exc->nil_p()) {
      vm_->interrupted_exception_.set(nil<Exception>());

      // Only write the locations if there are none.
      if(exc->locations()->nil_p() || exc->locations()->size() == 0) {
        exc->locations(this, Location::from_call_stack(this, call_frame));
      }

      vm_->thread_state_.raise_exception(exc);
      return false;
    }
    if(vm_->interrupt_by_kill()) {
      Fiber* fib = vm_->current_fiber.get();
      if(fib->nil_p() || fib->root_p()) {
        vm_->clear_interrupt_by_kill();
      } else {
        vm_->set_check_local_interrupts();
      }
      vm_->thread_state_.raise_thread_kill();
      return false;
    }

    return true;
  }

  bool State::check_interrupts(CallFrame* call_frame, void* end) {
    // First, we might be here because someone reset the stack_limit_ so that
    // we'd fall into here to check interrupts even if the stack is fine,
    //
    // So fix up the stack_limit_ if thats the case first.

    // If this is true, stack_limit_ was just changed to get our attention, reset
    // it now.
    if(!check_stack(call_frame, end)) return false;

    if(unlikely(check_local_interrupts())) {
      if(!process_async(call_frame)) return false;
    }

    // If the current thread is trying to step, debugger wise, then assist!
    if(vm_->thread_step()) {
      vm_->clear_thread_step();
      if(!Helpers::yield_debugger(this, call_frame, cNil)) return false;
    }

    return true;
  }


  Object* State::park(CallFrame* call_frame) {
    return vm_->park_->park(this, call_frame);
  }

  Object* State::park_timed(CallFrame* call_frame, struct timespec* ts) {
    return vm_->park_->park_timed(this, call_frame, ts);
  }
}
