#include <set>

#include "graph_adjacency_matrix.hpp"

template <class V, class E>
bool route_between_nodes(adjacency_matrix<V, E> const& graph,
                         std::size_t const origin,
                         std::size_t const destination) {
  std::size_t const n{graph.size()};
  for (std::set<std::size_t> next{origin}, past; !next.empty();) {
    std::size_t const current{std::move(next.extract(std::cbegin(next)).value())};
    for (std::size_t i{0}; i < n; ++i) {
      if (graph[{current, i}] && past.insert(i).second) {
        if (i == destination) return true;
        next.insert(i);
      }
    }
  }
  return false;
}
