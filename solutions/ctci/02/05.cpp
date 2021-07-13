#include <concepts>
#include <forward_list>

// Time O( n ) | Space O( n )
template <std::integral T>
constexpr std::forward_list<T> sum_list_reverse(std::forward_list<T> const& a,
                                                std::forward_list<T> const& b) {
  std::forward_list<T> sol;
  int remainder{0};
  auto it_sol{sol.cbefore_begin()};
  for (auto it_a{std::cbegin(a)}, last_a{std::cend(a)},
            it_b{std::cbegin(b)}, last_b{std::cend(b)};;) {
    bool const next_a{it_a != last_a}, next_b{it_b != last_b};
    if (!next_a && !next_b) break;
    int const sum{(next_a ? *it_a : 0) + (next_b ? *it_b : 0) + remainder};
    it_sol = sol.insert_after(it_sol, sum % 10);
    if (next_a) ++it_a;
    if (next_b) ++it_b;
    remainder = sum / 10;
  }
  if (remainder > 0) sol.insert_after(it_sol, remainder);
  return sol;
}

// Time O( n ) | Space O( n )
template <std::integral T>
constexpr std::pair<T, std::forward_list<T>> sum_list_forward_detail(typename std::forward_list<T>::const_iterator const& it_a,
                                                                     typename std::forward_list<T>::const_iterator const& last_a,
                                                                     typename std::forward_list<T>::const_iterator const& it_b,
                                                                     typename std::forward_list<T>::const_iterator const& last_b) {
  bool const next_a{it_a != last_a}, next_b{it_b != last_b};
  if (!next_a && !next_b) return {0, {}};
  auto [remainder, list]{sum_list_forward_detail<T>(next_a ? std::next(it_a) : it_a, last_a,
                                                    next_b ? std::next(it_b) : it_b, last_b)};
  int const sum{(next_a ? *it_a : 0) + (next_b ? *it_b : 0) + remainder};
  list.insert_after(list.cbefore_begin(), sum % 10);
  return {sum / 10, list};
}

// Time O( n ) | Space O( n )
template <std::integral T>
constexpr std::forward_list<T> sum_list_forward(std::forward_list<T> const& a,
                                                std::forward_list<T> const& b) {
  auto [remainder, list]{sum_list_forward_detail<T>(std::cbegin(a), std::cend(a),
                                                    std::cbegin(b), std::cend(b))};
  if (remainder > 0) list.insert_after(list.cbefore_begin(), remainder);
  return list;
}
