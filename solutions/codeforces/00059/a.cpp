/* Contest 59 - Problem A
 * https://codeforces.com/problemset/problem/59/A
 */

#include <algorithm>
#include <cctype>
#include <iostream>
#include <ranges>
#include <string>

std::string proccessWord(std::string const word) {
  auto const nLow{std::ranges::count_if(word, [](char const c) -> bool { return std::islower(c); })};
  auto const proccessed{word | std::ranges::views::transform(
                                   nLow * 2 >= std::ranges::size(word)
                                   ? [](char const c) -> char { return std::tolower(c); }
                                   : [](char const c) -> char { return std::toupper(c); })};
  return std::string{std::ranges::cbegin(proccessed), std::ranges::cend(proccessed)};
}

int main() {
  std::ranges::copy(proccessWord(*std::istream_iterator<std::string>{std::cin}),
                    std::ostream_iterator<char>{std::cout, ""});
}
