#include <bit>

uint32_t insertion(uint32_t const n, uint32_t const m, uint8_t const i, uint8_t const j) {
  return n & ((1 << i) - 1 | ~0 << j  + 1) | m << i;
}

uint32_t insertion(uint32_t const n, uint32_t const m, uint8_t const i) {
  return n & ((1 << i) - 1 | ~0 << (i + std::bit_width(m))) | m << i;
}
