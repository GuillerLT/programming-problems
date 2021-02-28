#ifndef glt_gcd_lcm
#define glt_gcd_lcm

#include <tuple>
#include <type_traits>

#include "math.hpp"

namespace glt {

template <typename A, typename B>
constexpr auto _gcd_ext(A const a, B const b)
    -> std::tuple<std::common_type_t<A, B>,
                  std::make_signed_t<std::common_type_t<A, B>>,
                  std::make_signed_t<std::common_type_t<A, B>>> {
  if (b == 0) {
    return {a, 1, 0};
  } else {
    auto const [gcd_v, x, y]{_gcd_ext(b, a % b)};
    return {gcd_v, y, x - a / b * y};
  }
}

template <typename A, typename B>
constexpr auto gcd_ext(A const a, B const b)
    -> std::tuple<std::common_type_t<A, B>,
                  std::make_signed_t<std::common_type_t<A, B>>,
                  std::make_signed_t<std::common_type_t<A, B>>> {
  auto const [gcd_v, x, y]{_gcd_ext(abs(a), abs(b))};
  return {gcd_v, x * sign(a), y * sign(b)};
}

}  // namespace glt

#endif
