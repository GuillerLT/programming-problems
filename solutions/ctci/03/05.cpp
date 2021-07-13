#include <stack>

// Time O( n^2 )
template <class T>
std::stack<T> sort(std::stack<T> stack) {
  std::stack<T> sorted;
  while (!stack.empty()) {
    T temp{std::move(stack.top())};
    stack.pop();
    while (!sorted.empty() && sorted.top() < temp) {
      stack.push(std::move(sorted.top()));
      sorted.pop();
    }
    sorted.push(std::move(temp));
  }
  return sorted;
}
