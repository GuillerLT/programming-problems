#include <array>
#include <cstdint>

uint64_t triple_step(uint32_t const n) {
  std::array<uint64_t, 3> staircase{1ull, 1ull, 2ull};
  for (uint32_t i = 3; i <= n; ++i) {
    staircase[i % 3] = staircase[0] + staircase[1] + staircase[2];
  }
  return staircase[n % 3];
}
