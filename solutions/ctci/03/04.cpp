#include <stack>

template <class T>
class queue {
 public:
  std::size_t size() const {
    return stack_new.size() + stack_old.size();
  }

  void push(T const& t) {
    stack_new.push(t);
  }

  T& front() {
    shift_stacks();
    return stack_old.top();
  }

  T const& front() const {
    shift_stacks();
    return stack_old.top();
  }

  void pop() {
    shift_stacks();
    stack_old.pop();
  }

 private:
  void shift_stacks() {
    if (stack_old.empty()) {
      while (!stack_new.empty()) {
        stack_old.push(stack_new.top());
        stack_new.pop();
      }
    }
  }

  mutable std::stack<T> stack_new, stack_old;
};
