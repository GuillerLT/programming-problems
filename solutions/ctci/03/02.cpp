#include <stack>

template <class T>
class stack_min {
 public:
  bool empty() const {
    return data.empty();
  }

  T const& top() const {
    return data.top().first;
  }

  T const& min() const {
    auto const& [a, b]{data.top()};
    return std::min(a, b);
  }

  void push(T const& t) {
    data.push({t, data.empty() ? t : std::min(t, data.top().second)});
  }

  void pop() {
    data.pop();
  }

 private:
  std::stack<std::pair<T, T>> data;
};
