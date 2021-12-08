/* Year 2021 - Day 3
 * https://adventofcode.com/2021/day/3
 */

#include <format>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "range/v3/all.hpp"

uint32_t part1(std::ifstream input) {
  auto const data =
      ranges::istream_range<std::string>(input) |
      ranges::to<std::vector<std::string>>();

  auto const gamma = ranges::accumulate(
    ranges::accumulate(
      data | ranges::view::transform([](std::string const& n) {
        return n |
               ranges::view::transform([](char const i) { return i == '1'; }) |
               ranges::to<std::vector<bool>>();
      }),
      std::vector<uint32_t>(12, 0),
      [](auto const accum, auto const bits) {
        return ranges::views::zip(accum, bits) |
               ranges::view::transform([](auto const ab) { return ab.first + ab.second; }) |
               ranges::to<std::vector<uint32_t>>();
      }),
    0u,
    [size = ranges::size(data)](auto const gamma, auto const cnt) {
      return (gamma << 1) | (cnt * 2 >= size);
    });


  return gamma * (~gamma & 0b1111'1111'1111);
}

int main() {
  std::format_to(std::ostream_iterator<char>{std::cout, ""}, "{}\n", part1(std::ifstream{"input1.txt"}));
}
