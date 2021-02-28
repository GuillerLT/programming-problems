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

}  // namespace glt

#endif
