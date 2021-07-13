#include <algorithm>
#include <list>

// Time O( n )
template <class T>
constexpr bool palindrome(std::list<T> const& list) {
  return std::equal(std::cbegin(list), std::cend(list),
                    std::crbegin(list), std::crend(list));
}
