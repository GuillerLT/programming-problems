#ifndef glt_segment_tree
#define glt_segment_tree

#include <utility>
#include <vector>

namespace glt {

/* Segment Tree class
 * This implementation only allows for eager initialization and does not
 * support later update operations yet.
 * More details of segment tree data structure are available on
 * https://cp-algorithms.com/data_structures/segment_tree.html
 *
 * Template parameters constraints
 * - RandomAccessContainer: Container from which the segment tree is built.
 *   - std::size_t size(): Returns the number of elements in the container.
 *   - T operator[](std::size_t): Returns the element at the specified position
 * in the container.
 * - Manipulator: Class that implements the methods to build and query the
 *   segment tree.
 *   - Copy constructible.
 *   - V query(T): Receives a value from the random access container and
 *     returns a segment tree node.
 *   - V query(V, V): Receives two values from the segment tree and returns
 *     a new segment tree node. Used to build parent nodes and for queries.
 *   - V identity(): Return the identity element.
 *     query(identity, V) == query(V, identity) == V
 *     https://en.wikipedia.org/wiki/Identity_element
 *
 * Example of use
 * https://github.com/GuillerLT/competitive-programming/blob/main/solutions/codeforces/00380/c.cpp
 */
template <typename Manipulator, typename RandomAccessContainer>
class segment_tree {
  using Value = decltype(std::declval<Manipulator>().identity());

 private:
  Manipulator manipulator;
  std::size_t size;
  std::vector<Value> values;

  Value const& update(RandomAccessContainer const& randomAccessContainer,
                      std::size_t const l, std::size_t const r,
                      std::size_t const i = 1) {
    Value& value = values[i];
    if (l == r) {
      // Leaf node
      value = manipulator.query(randomAccessContainer[l]);
    } else {
      // Non-leaf node
      std::size_t const m = l + (r - l) / 2;
      value = manipulator.query(
          update(randomAccessContainer, l,     m, i << 1),
          update(randomAccessContainer, m + 1, r, i << 1 | 1));
    }
    return value;
  }

  Value query(std::size_t const lquery, std::size_t const rquery,
              std::size_t const l,      std::size_t const r,
              std::size_t const i = 1) const {
    if (lquery <= l && rquery >= r) {
      // Inside query range
      return values[i];
    } else if (rquery < l || lquery > r) {
      // Outside query range
      return manipulator.identity();
    } else {
      // Overlapping query range
      std::size_t const m = l + (r - l) / 2;
      return manipulator.query(query(lquery, rquery, l,     m, i << 1),
                               query(lquery, rquery, m + 1, r, i << 1 | 1));
    }
  }

 public:
  segment_tree(Manipulator const& manipulator,
               RandomAccessContainer const& randomAccessContainer)
      : manipulator(manipulator),
        size(randomAccessContainer.size()),
        values(randomAccessContainer.size() << 2) {
    // Eager initialization
    update(randomAccessContainer, 0, size - 1);
  }

  // Preconditions:
  // - 0 <= lquery <= rquery < size
  Value query(std::size_t const lquery, std::size_t const rquery) const {
    return query(lquery, rquery, 0, size - 1);
  }
};

}  // namespace glt

#endif
