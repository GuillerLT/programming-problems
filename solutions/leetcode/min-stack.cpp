/* Problem min-stack
 * https://www.leetcode.com/problems/min-stack
 */

#include <stack>

using namespace std;

class MinStack {
 private:
  stack<pair<int, int>> stack_;

 public:
  void push(int const x) {
    if (stack_.empty()) {
      stack_.push(make_pair(x, x));
    } else {
      stack_.push(make_pair(x, min(x, stack_.top().second)));
    }
  }

  void pop() { stack_.pop(); }

  int top() const { return stack_.top().first; }

  int getMin() const { return stack_.top().second; }
};
