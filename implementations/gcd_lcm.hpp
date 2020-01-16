#ifndef glt_gcd_lcm
#define glt_gcd_lcm

namespace glt {

template <typename T>
T gcd(T a, T b) {
  while (b != static_cast<T>(0)) {
    long long const c = a % b;
    a = b;
    b = c;
  }
  return a;
}

template <typename T>
T lcm(T const a, T const b) {
  return a * b / gcd(a, b);
}

}  // namespace glt

#endif
