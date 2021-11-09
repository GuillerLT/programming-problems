/* Contest 110 - Problem A
 * https://codeforces.com/problemset/problem/110/A
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>

int main() {
  auto const isLuckyDigit{[](char const c) { return c == '4' || c == '7'; }};
  std::cout << (std::ranges::all_of(
                  std::to_string(
                    std::ranges::count_if(
                      *std::istream_iterator<std::string>{std::cin},
                      isLuckyDigit
                    )
                  ),
                  isLuckyDigit
                )
                ? "YES"
                : "NO");
}
