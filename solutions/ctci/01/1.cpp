#include <algorithm>
#include <bitset>
#include <string_view>

// Time O( n ) | Space O( m )
constexpr bool is_unique_time(std::string_view const str) {
  std::bitset<256> chars;
  for (char const c : str) {
    if (chars.test(static_cast<std::size_t>(c))) return false;
    chars.set(static_cast<std::size_t>(c));
  }
  return true;
}

// Time O( n log(n) ) | Space O( 1 )
bool is_unique_space(std::string_view const str) {
  if (str.empty()) return true;
  std::string str_aux{str};
  std::sort(std::begin(str_aux), std::end(str_aux));
  auto const last{std::cend(str_aux)};
  for (auto first{std::next(std::cbegin(str_aux))}; first != last; ++first) {
    if (*first == *std::prev(first)) return false;
  }
  return true;
}
