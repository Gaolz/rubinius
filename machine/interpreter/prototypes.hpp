#ifndef RBX_INTERPRETER_PROTOTYPES_HPP
#define RBX_INTERPRETER_PROTOTYPES_HPP

namespace rubinius {
  namespace instructions {
    using namespace rubinius;

    typedef enum {
      cExceptionUnwind,
      cExceptionContinue,
      cExceptionReturn,
    } ExceptionContinuation;

    inline void add_scope(STATE, CallFrame* call_frame);
    inline void allow_private();
    inline bool cast_array(STATE, CallFrame* call_frame);
    inline bool cast_for_multi_block_arg(STATE, CallFrame* call_frame);
    inline bool cast_for_single_block_arg(STATE, CallFrame* call_frame);
    inline bool cast_for_splat_block_arg(STATE, CallFrame* call_frame);
    inline bool cast_multi_value(STATE, CallFrame* call_frame);
    inline bool check_frozen(STATE, CallFrame* call_frame);
    inline void check_interrupts(STATE);
    inline void check_serial(STATE, CallFrame* call_frame, intptr_t literal, intptr_t serial);
    inline void check_serial_private(STATE, CallFrame* call_frame, intptr_t literal, intptr_t serial);
    inline void clear_exception(STATE);
    inline bool create_block(STATE, CallFrame* call_frame, intptr_t literal);
    inline void dup(CallFrame* call_frame);
    inline void dup_many(CallFrame* call_frame, intptr_t count);
    inline intptr_t ensure_return(STATE, CallFrame* call_frame);
    inline bool find_const(STATE, CallFrame* call_frame, intptr_t literal);
    inline void goto_(CallFrame* call_frame);
    inline bool goto_if_equal(CallFrame* call_frame);
    inline bool goto_if_false(CallFrame* call_frame);
    inline bool goto_if_nil(CallFrame* call_frame);
    inline bool goto_if_not_equal(CallFrame* call_frame);
    inline bool goto_if_not_nil(CallFrame* call_frame);
    inline bool goto_if_not_undefined(STATE, CallFrame* call_frame);
    inline bool goto_if_true(CallFrame* call_frame);
    inline bool goto_if_undefined(STATE, CallFrame* call_frame);
    inline void instance_of(STATE, CallFrame* call_frame);
    inline bool invoke_primitive(STATE, CallFrame* call_frame, intptr_t literal, intptr_t count);
    inline void kind_of(STATE, CallFrame* call_frame);
    inline void make_array(STATE, CallFrame* call_frame, intptr_t count);
    inline void move_down(CallFrame* call_frame, intptr_t positions);
    inline void noop();
    inline bool object_to_s(STATE, CallFrame* call_frame, intptr_t literal);
    inline bool passed_arg(STATE, CallFrame* call_frame, intptr_t index);
    inline bool passed_blockarg(STATE, CallFrame* call_frame, intptr_t count);
    inline void pop(CallFrame* call_frame);
    inline void pop_many(CallFrame* call_frame, intptr_t count);
    inline bool pop_unwind(STATE, CallFrame* call_frame);
    inline void push_block(STATE, CallFrame* call_frame);
    inline bool push_block_arg(STATE, CallFrame* call_frame);
    inline bool push_const(STATE, CallFrame* call_frame, intptr_t literal);
    inline void push_cpath_top(STATE, CallFrame* call_frame);
    inline void push_current_exception(STATE, CallFrame* call_frame);
    inline void push_exception_state(STATE, CallFrame* call_frame);
    inline void push_false(CallFrame* call_frame);
    inline void push_has_block(CallFrame* call_frame);
    inline void push_int(CallFrame* call_frame, intptr_t number);
    inline bool push_ivar(STATE, CallFrame* call_frame, intptr_t literal);
    inline void push_literal(CallFrame* call_frame, intptr_t literal);
    inline void push_local(CallFrame* call_frame, intptr_t local);
    inline bool push_local_depth(STATE, CallFrame* call_frame, intptr_t depth, intptr_t index);
    inline void push_memo(CallFrame* call_frame, intptr_t literal);
    inline void push_mirror(STATE, CallFrame* call_frame);
    inline void push_my_field(STATE, CallFrame* call_frame, intptr_t index);
    inline void push_my_offset(CallFrame* call_frame, intptr_t index);
    inline void push_nil(CallFrame* call_frame);
    inline bool push_proc(STATE, CallFrame* call_frame);
    inline void push_rubinius(STATE, CallFrame* call_frame);
    inline void push_scope(CallFrame* call_frame);
    inline void push_self(CallFrame* call_frame);
    inline void push_stack_local(CallFrame* call_frame, intptr_t which);
    inline void push_true(CallFrame* call_frame);
    inline void push_type(STATE, CallFrame* call_frame);
    inline void push_undef(STATE, CallFrame* call_frame);
    inline void push_variables(STATE, CallFrame* call_frame);
    inline intptr_t raise_break(STATE, CallFrame* call_frame);
    inline void raise_exc(STATE, CallFrame* call_frame);
    inline void raise_return(STATE, CallFrame* call_frame);
    inline void reraise(STATE, CallFrame* call_frame);
    inline void restore_exception_state(STATE, CallFrame* call_frame);
    inline intptr_t ret(STATE, CallFrame* call_frame);
    inline void rotate(CallFrame* call_frame, intptr_t count);
    inline ExceptionContinuation run_exception(STATE, CallFrame* call_frame);
    inline bool send_method(STATE, CallFrame* call_frame, intptr_t literal);
    inline bool send_stack(STATE, CallFrame* call_frame, intptr_t literal, intptr_t count);
    inline bool send_stack_with_block(STATE, CallFrame* call_frame, intptr_t literal, intptr_t count);
    inline bool send_stack_with_splat(STATE, CallFrame* call_frame, intptr_t literal, intptr_t count);
    inline bool send_super_stack_with_block(STATE, CallFrame* call_frame, intptr_t literal, intptr_t count);
    inline bool send_super_stack_with_splat(STATE, CallFrame* call_frame, intptr_t literal, intptr_t count);
    inline bool send_vcall(STATE, CallFrame* call_frame, intptr_t literal);
    inline void set_call_flags(CallFrame* call_frame);
    inline void set_const(STATE, CallFrame* call_frame, intptr_t literal);
    inline void set_const_at(STATE, CallFrame* call_frame, intptr_t literal);
    inline bool set_ivar(STATE, CallFrame* call_frame, intptr_t literal);
    inline void set_local(CallFrame* call_frame, intptr_t local);
    inline bool set_local_depth(STATE, CallFrame* call_frame, intptr_t depth, intptr_t index);
    inline void set_stack_local(CallFrame* call_frame, intptr_t which);
    inline void setup_unwind(CallFrame* call_frame, intptr_t ip, intptr_t type);
    inline void shift_array(STATE, CallFrame* call_frame);
    inline bool store_my_field(STATE, CallFrame* call_frame, intptr_t index);
    inline void string_append(STATE, CallFrame* call_frame);
    inline bool string_build(STATE, CallFrame* call_frame, intptr_t count);
    inline bool string_dup(STATE, CallFrame* call_frame);
    inline void swap(CallFrame* call_frame);
    inline void yield_debugger(STATE);
    inline bool yield_splat(STATE, CallFrame* call_frame, intptr_t count);
    inline bool yield_stack(STATE, CallFrame* call_frame, intptr_t count);
    inline bool zsuper(STATE, CallFrame* call_frame, intptr_t literal);
  }

  namespace interpreter {
    using namespace rubinius;

    intptr_t add_scope(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t allow_private(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t cast_array(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t cast_for_multi_block_arg(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t cast_for_single_block_arg(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t cast_for_splat_block_arg(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t cast_multi_value(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t check_frozen(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t check_interrupts(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t check_serial(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t check_serial_private(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t clear_exception(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t create_block(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t dup(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t dup_many(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t ensure_return(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t find_const(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t goto_(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t goto_if_equal(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t goto_if_false(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t goto_if_nil(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t goto_if_not_equal(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t goto_if_not_nil(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t goto_if_not_undefined(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t goto_if_true(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t goto_if_undefined(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t instance_of(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t invoke_primitive(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t kind_of(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t make_array(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t move_down(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t noop(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t object_to_s(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t passed_arg(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t passed_blockarg(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t pop(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t pop_many(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t pop_unwind(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_block(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_block_arg(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_const(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_cpath_top(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_current_exception(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_exception_state(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_false(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_has_block(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_int(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_ivar(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_literal(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_local(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_local_depth(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_memo(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_mirror(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_my_field(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_my_offset(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_nil(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_proc(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_rubinius(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_scope(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_self(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_stack_local(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_true(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_type(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_undef(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t push_variables(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t raise_break(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t raise_exc(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t raise_return(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t reraise(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t restore_exception_state(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t ret(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t rotate(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t run_exception(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t send_method(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t send_stack(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t send_stack_with_block(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t send_stack_with_splat(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t send_super_stack_with_block(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t send_super_stack_with_splat(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t send_vcall(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t set_call_flags(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t set_const(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t set_const_at(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t set_ivar(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t set_local(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t set_local_depth(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t set_stack_local(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t setup_unwind(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t shift_array(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t store_my_field(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t string_append(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t string_build(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t string_dup(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t swap(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t yield_debugger(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t yield_splat(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t yield_stack(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
    intptr_t zsuper(STATE, CallFrame* call_frame, intptr_t const opcodes[]);
  }
}

#endif
