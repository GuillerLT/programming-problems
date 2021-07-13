#include <concepts>
#include <forward_list>
#include <utility>

// Time O( n )
template <class T>
std::forward_list<T> erase(std::forward_list<T>&& list,
                           typename std::forward_list<T>::iterator it) {
  auto const last{std::cend(list)};
  for (auto next{std::next(it)};; ++it, ++next) {
    std::iter_swap(it, next);
    if (std::next(next) == last) {
      list.erase_after(it);
      break;
    }
  }
  return std::move(list);
}
