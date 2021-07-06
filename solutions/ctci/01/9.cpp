#include <string>
#include <string_view>

constexpr bool is_substring(std::string_view const sub_str,
                            std::string_view const str) {
  return str.find(sub_str) != std::string_view::npos;
}

bool string_rotation(std::string_view const str1,
                     std::string_view const str2) {
  return is_substring(str1, std::string{str2} + std::string{str2});
}
