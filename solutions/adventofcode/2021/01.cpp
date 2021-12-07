/* Year 2021 - Day 1
 * https://adventofcode.com/2021/day/1
 */

#include <format>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

#include "range/v3/algorithm.hpp"
#include "range/v3/view/sliding.hpp"
#include "range/v3/view/transform.hpp"

uint32_t part1(std::ifstream input) {
  std::vector<int32_t> const data{std::istream_iterator<int32_t>{input}, std::istream_iterator<int32_t>{}};
  return ranges::count_if(
      data | ranges::view::sliding(2),
      [](auto const pair) { return pair[1] > pair[0]; });
}

uint32_t part2(std::ifstream input) {
  std::vector<int32_t> const data{std::istream_iterator<int32_t>{input}, std::istream_iterator<int32_t>{}};
  return ranges::count_if(
      data |
          ranges::view::sliding(3) |
          ranges::view::transform([](auto const window) { return window[0] + window[1] + window[2]; }) |
          ranges::view::sliding(2),
      [](auto const pair) { return pair[1] > pair[0]; });
}

int main() {
  std::format_to(std::ostream_iterator<char>{std::cout, ""}, "{}\n", part1(std::ifstream{"input1.txt"}));
  std::format_to(std::ostream_iterator<char>{std::cout, ""}, "{}\n", part1(std::ifstream{"input2.txt"}));
  return 0;
}
