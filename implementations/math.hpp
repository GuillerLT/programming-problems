#ifndef glt_math
#define glt_math

#include <type_traits>

namespace glt {

template <typename T>
constexpr auto abs(T const t) -> T {
  return t < 0 ? -t : t;
}

template <typename T>
constexpr auto sign(T const t) -> std::make_signed_t<T> {
  return t < 0 ? -1 : t > 0 ? +1 : 0;
}

template <class Integral1, class Integral2>
constexpr auto int_pow(Integral1 i1, Integral2 i2)
    -> std::common_type_t<Integral1, Integral2> {
  std::common_type_t<Integral1, Integral2> ans{1};
  while (i2 > 0) {
    if (i2 & 1) ans *= i1;
    i1 *= i1;
    i2 >>= 1;
  }
  return ans;
}

}  // namespace glt

#endif
