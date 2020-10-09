#ifndef glt_binary_indexed_tree
#define glt_binary_indexed_tree

#include <algorithm>
#include <iterator>

namespace glt {

/* Binary Indexed (Fenwick) Tree
 * http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.14.8917&rep=rep1&type=pdf
 */

template <typename ForwardIt, typename T>
constexpr auto update_binary_indexed_tree(ForwardIt const first,
                                          ForwardIt const pos,
                                          ForwardIt const last, T const delta)
    -> void {
  auto const size = std::distance(first, last);
  for (auto index = std::distance(first, pos) + 1; index <= size;
       index += (index & -index)) {
    *std::next(first, index - 1) += delta;
  }
}

template <typename ForwardIt>
constexpr auto query_binary_indexed_tree(ForwardIt const first,
                                         ForwardIt const last) ->
    typename std::iterator_traits<ForwardIt>::value_type {
  auto query =
      static_cast<typename std::iterator_traits<ForwardIt>::value_type>(0);
  for (auto index = std::distance(first, last); index > 0;
       index -= (index & -index)) {
    query += *std::next(first, index - 1);
  }
  return query;
}

template <typename InputIt, typename OutputIt>
constexpr void make_binary_indexed_tree(InputIt first, InputIt const last,
                                        OutputIt const d_first) {
  auto const size = std::distance(first, last);
  auto const d_last = std::next(d_first, size);
  std::fill(d_first, d_last, 0);
  for (auto d_pos = d_first; d_pos != d_last; ++first, ++d_pos) {
    update_binary_indexed_tree(d_first, d_pos, d_last, *first);
  }
}

}  // namespace glt

#endif
