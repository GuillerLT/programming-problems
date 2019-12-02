#ifndef glt_binary_indexed_tree
#define glt_binary_indexed_tree

#include <utility>
#include <vector>

namespace glt {

/* Binary Indexed (Fenwick) Tree class
 * http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.14.8917&rep=rep1&type=pdf
 */
template <typename T = int>
class binary_indexed_tree {
 private:
  std::vector<T> values;

  T _query(size_t rquery) {
    T value = static_cast<T>(0);
    while (rquery > 0) {
      value += values[rquery];
      rquery -= (rquery & -rquery);
    }
    return value;
  }
  void _update(size_t index, T const delta) {
    while (index < values.size()) {
      values[index] += delta;
      index += (index & -index);
    }
  }

 public:
  binary_indexed_tree(size_t const n) : values(n + 1, static_cast<T>(0)) {}
  // Preconditions:
  // - 0 <= lquery <= rquery < size
  T query(size_t const lquery, size_t const rquery) {
    return _query(rquery + 1) - _query(lquery);
  }
  // Preconditions:
  // - 0 <= rquery < size
  T query(size_t const rquery) { return _query(rquery + 1); }
  // Preconditions:
  // - 0 <= index < size
  void update(size_t const index, T const delta) { _update(index + 1, delta); }
};

}  // namespace glt

#endif
