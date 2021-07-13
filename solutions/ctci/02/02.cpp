#include <concepts>
#include <forward_list>
#include <iterator>

// Time O( n )
template <std::forward_iterator T>
constexpr std::pair<typename std::iterator_traits<T>::value_type, std::size_t>
kth_last_detail(T const first, T const last, std::size_t const k) {
  if (first == last) return {value_type{}, std::size_t{0}};
  auto const [t, i]{kth_last_detail(std::next(first), last, k)};
  return {i > k ? t : *first, i + 1};
}

template <std::forward_iterator T>
constexpr typename std::iterator_traits<T>::value_type
kth_last(T const first, T const last, std::size_t const k) {
  return kth_last_detail(first, last, k).first;
}
