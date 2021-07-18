#pragma once

#include <utility>
#include <vector>

template <class V, class E>
class adjacency_matrix {
 public:
  adjacency_matrix(std::size_t const n) : vertices_(n), edges_(n * n) {}

  std::size_t size() const { return vertices_.size(); }

  V      & operator[](std::size_t const v)      & { return vertices_[v]; }
  V const& operator[](std::size_t const v) const& { return vertices_[v]; }
  V     && operator[](std::size_t const v)     && { return std::move(vertices_[v]); }

  E      & operator[](std::pair<std::size_t, std::size_t> const e)      & { return edges_[e.first * vertices_.size() + e.second]; }
  E const& operator[](std::pair<std::size_t, std::size_t> const e) const& { return edges_[e.first * vertices_.size() + e.second]; }
  E     && operator[](std::pair<std::size_t, std::size_t> const e)     && { return std::move(edges_[e.first * vertices_.size() + e.second]); }

 private:
  std::vector<V> vertices_;
  std::vector<E> edges_;
};
