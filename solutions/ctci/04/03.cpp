#include <algorithm>
#include <list>
#include <vector>

#include "binary_tree.hpp"

template <class T>
std::vector<std::list<std::reference_wrapper<binary_tree<T> const>>> list_of_depths(binary_tree<T> const &tree) {
  using list = std::list<std::reference_wrapper<binary_tree<T> const>>;
  std::vector<list> l{tree.left() ? list_of_depths(*(tree.left().get())) : std::vector<list>{}};
  std::vector<list> r{tree.right() ? list_of_depths(*(tree.right().get())) : std::vector<list>{}};
  std::vector<list> depths(std::max(l.size(), r.size()) + 1);
  depths.front().push_back(tree);
  auto merge{[](list &l1, list &l2) {
    l2.splice(std::ranges::cend(l2), std::move(l1));
    return std::move(l2);
  }};
  std::ranges::transform(std::ranges::begin(l), std::ranges::end(l),
                         std::ranges::next(std::ranges::begin(depths)), std::ranges::end(depths),
                         std::ranges::next(std::ranges::begin(depths)),
                         merge);
  std::ranges::transform(std::ranges::begin(r), std::ranges::end(r),
                         std::ranges::next(std::ranges::begin(depths)), std::ranges::end(depths),
                         std::ranges::next(std::ranges::begin(depths)),
                         merge);
  return depths;
}
