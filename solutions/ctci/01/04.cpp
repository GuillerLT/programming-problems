#include <string_view>
#include <bitset>

// Time O( n ) | Space O( m )
constexpr bool palindrome_permutation(std::string_view const str) {
  std::bitset<256> evens;
  for (char const c : str) evens.flip(static_cast<std::size_t>(c));
  return evens.count() == (str.size() & 0b1ull);
}
