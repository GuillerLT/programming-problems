#include <concepts>
#include <ranges>

#include "binary_tree.hpp"

template <std::ranges::forward_range R>
binary_tree<std::ranges::range_value_t<R>> minimal_tree_detail(R const r) {
  auto const begin{std::ranges::cbegin(r)}, end{std::ranges::cend(r)};
  auto const mid{std::ranges::next(begin, std::ranges::distance(begin, end) / 2)};
  return binary_tree<std::ranges::range_value_t<R>>{
      *mid,
      begin == mid
          ? nullptr
          : std::make_unique<binary_tree<std::ranges::range_value_t<R>>>(
                minimal_tree_detail(std::ranges::subrange{begin, mid})),
      std::ranges::next(mid) == end
          ? nullptr
          : std::make_unique<binary_tree<std::ranges::range_value_t<R>>>(
                minimal_tree_detail(std::ranges::subrange{std::ranges::next(mid), end}))};
}

template <std::ranges::forward_range R>
binary_tree<std::ranges::range_value_t<R>> minimal_tree(R const r) {
  return std::ranges::distance(r) ? minimal_tree_detail(r)
                                  : binary_tree<std::ranges::range_value_t<R>>{};
}
