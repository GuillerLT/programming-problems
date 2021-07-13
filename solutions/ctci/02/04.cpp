#include <list>

// Time O( n )
template <class T>
constexpr std::list<T> partition(std::list<T> list, T const value) {
  std::list<T> l, g;
  while (!list.empty()) {
    auto const it{list.cbegin()};
    auto& target{*it < value ? l : g};
    target.splice(std::cend(target), list, it);
  }
  list.splice(std::cend(list), std::move(l));
  list.splice(std::cend(list), std::move(g));
  return std::move(list);
}
