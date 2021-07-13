#include <algorithm>
#include <list>
#include <unordered_set>

// Time O( n ) | Space O( n )
template <class T>
constexpr std::list<T> remove_dups_time(std::list<T> list) {
  std::unordered_set<T> aux;
  auto const last{std::cend(list)};
  for (auto it{std::cbegin(list)}; it != last;) {
    it = aux.insert(*it).second ? std::next(it)
                                : list.erase(it);
  }
  return list;
}

// Time O( n^2 )
template <class T>
constexpr std::list<T> remove_dups_space(std::list<T> list) {
  auto const last{std::cend(list)};
  for (auto it{std::cbegin(list)}; it != last;) {
    it = (std::find(std::cbegin(list), it, *it) == it) ? std::next(it)
                                                       : list.erase(it);
  }
  return list;
}