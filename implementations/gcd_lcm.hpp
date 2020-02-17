#ifndef glt_gcd_lcm
#define glt_gcd_lcm

namespace glt {

template <typename T>
T gcd(T a, T b) {
  while (b != static_cast<T>(0LL)) {
    T const c = a % b;
    a = b;
    b = c;
  }
  return abs(a);
}

template <typename T>
T lcm(T const a, T const b) {
  return abs(a * (b / gcd(a, b)));
}

}  // namespace glt

#endif
