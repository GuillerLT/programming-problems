/* Year 2021 - Day 2
 * https://adventofcode.com/2021/day/2
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

int64_t part1(std::ifstream input) {
  std::vector<std::string> const data{std::istream_iterator<std::string>{input}, std::istream_iterator<std::string>{}};
  auto const [h, d] =
      ranges::accumulate(
          data |
              ranges::view::sliding(2) |
              ranges::view::stride(2) |
              ranges::view::transform([](auto const action) {
                if (action[0] == "forward") {
                  return std::pair<int64_t, int64_t>{+std::stoll(action[1]), 0ll};
                }
                if (action[0] == "down") {
                  return std::pair<int64_t, int64_t>{0ll, +std::stoll(action[1])};
                }
                if (action[0] == "up") {
                  return std::pair<int64_t, int64_t>{0ll, -std::stoll(action[1])};
                }
                return std::pair<int64_t, int64_t>{0ll, 0ll};
              }),
          std::pair<int64_t, int64_t>{0ll, 0ll},
          [](auto const hd, auto const hd_delta) {
            return std::pair<int64_t, int64_t>{hd.first + hd_delta.first, hd.second + hd_delta.second};
          });
  return h * d;
}

int64_t part2(std::ifstream input) {
  std::vector<std::string> const data{std::istream_iterator<std::string>{input}, std::istream_iterator<std::string>{}};
  auto const [h, d, a] =
      ranges::accumulate(
          data |
              ranges::view::sliding(2) |
              ranges::view::stride(2) |
              ranges::view::transform([](auto const action) {
                if (action[0] == "forward") {
                  return std::tuple<int64_t, int64_t>{+std::stoll(action[1]), 0};
                }
                if (action[0] == "down") {
                  return std::tuple<int64_t, int64_t>{0, +std::stoll(action[1])};
                }
                if (action[0] == "up") {
                  return std::tuple<int64_t, int64_t>{0, -std::stoll(action[1])};
                }
                return std::tuple<int64_t, int64_t>{0ll, 0ll};
              }),
          std::tuple<int64_t, int64_t, int64_t>{0ll, 0ll, 0ll},
          [](auto const hda, auto const ha_delta) {
            return std::tuple<int64_t, int64_t, int64_t>{
                std::get<0>(hda) + get<0>(ha_delta),
                std::get<1>(hda) + get<0>(ha_delta) * get<2>(hda),
                std::get<2>(hda) + get<1>(ha_delta),
            };
          });
  return h * d;
}

int main() {
  std::format_to(std::ostream_iterator<char>{std::cout, ""}, "{}\n", part1(std::ifstream{"input1.txt"}));
  std::format_to(std::ostream_iterator<char>{std::cout, ""}, "{}\n", part2(std::ifstream{"input2.txt"}));
}
