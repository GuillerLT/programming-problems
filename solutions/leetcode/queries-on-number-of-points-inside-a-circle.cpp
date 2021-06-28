/* Problem queries-on-number-of-points-inside-a-circle
 * https://www.leetcode.com/problems/queries-on-number-of-points-inside-a-circle
 */

#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <numeric>
#include <vector>

class Solution {
 public:
  static std::vector<int> countPoints(std::vector<std::vector<int>> const& points,
                                      std::vector<std::vector<int>> const& queries) {
    std::map<int, std::map<int, int>> xyf;
    for (std::vector<int> const& point : std::move(points)) ++xyf[point[0]][point[1]];
    std::vector<int> sols(queries.size());
    std::transform(
        std::cbegin(queries), std::cend(queries), std::begin(sols),
        [&xyf = std::as_const(xyf)](std::vector<int> const& query) {
          int const
              xq{query[0]},
              yq{query[1]},
              rq{query[2]};
          return std::transform_reduce(
              xyf.lower_bound(xq - rq), xyf.upper_bound(xq + rq),
              0, std::plus{},
              [xq, yq, rq](auto const& x_yf) {
                auto const x{x_yf.first};
                auto const& yf{x_yf.second};
                return std::transform_reduce(
                    yf.lower_bound(yq - rq), yf.upper_bound(yq + rq),
                    0, std::plus{},
                    [x, xq, yq, rq](auto const& y_f) {
                      auto const y{y_f.first};
                      auto const f{y_f.second};
                      auto const dx{std::abs(x - xq)};
                      auto const dy{std::abs(y - yq)};
                      return std::sqrt(dx * dx + dy * dy) <= rq ? f : 0;
                    });
              });
        });
    return sols;
  }
};
