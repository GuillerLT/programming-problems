/* Contest 1076 - Problem A
 * https://codeforces.com/problemset/problem/1076/A
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <functional>

int main() {
  std::string const s{*++std::istream_iterator<std::string>{std::cin}};

  auto const it{
    std::min(
      std::ranges::adjacent_find(s, std::greater{}),
      std::prev(std::ranges::cend(s))
    )
  };

  auto out_it{std::ostream_iterator<char>{std::cout, ""}};
  std::ranges::copy(std::ranges::cbegin(s), it, out_it);
  std::ranges::copy(std::next(it), std::ranges::cend(s), out_it);
}
