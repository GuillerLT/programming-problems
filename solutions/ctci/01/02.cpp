#include <algorithm>
#include <array>
#include <string_view>

// Time O( n ) | Space O( m )
constexpr bool check_permutation_time(std::string_view const str1,
                                      std::string_view const str2) {
  if (str1.size() != str2.size()) return false;
  std::array<std::size_t, 256> freq{};
  for (char const c : str1) freq[static_cast<std::size_t>(c)] += 1ull;
  for (char const c : str2) freq[static_cast<std::size_t>(c)] -= 1ull;
  for (std::size_t const f : freq) if (f != 0) return false;
  return true;
}

// Time O( n log(n) ) | Space O(1)
bool check_permutation_space(std::string&& str1,
                             std::string&& str2) {
  if (str1.size() != str2.size()) return false;
  std::sort(std::begin(str1), std::end(str1));
  std::sort(std::begin(str2), std::end(str2));
  return std::equal(std::cbegin(str1), std::cend(str1),
                    std::cbegin(str2));
}
