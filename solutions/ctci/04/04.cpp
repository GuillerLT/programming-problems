#include <utility>

#include "binary_tree.hpp"

template <class T>
std::pair<bool, std::size_t> check_balanced_detail(binary_tree<T> const& tree) {
  auto const [l_ok, l_depth]{tree.left() ? check_balanced_detail(*tree.left().get())
                                         : std::pair{true, std::size_t{0}}};
  auto const [r_ok, r_depth]{tree.right() ? check_balanced_detail(*tree.right().get())
                                          : std::pair{true, std::size_t{0}}};
  return {l_ok && r_ok && (std::max(l_depth, r_depth) - std::min(l_depth, r_depth)) <= 1,
          std::max(l_depth, r_depth) + 1};
}

template <class T>
bool check_balanced(binary_tree<T> const& tree) {
  return check_balanced_detail(tree).first;
}
