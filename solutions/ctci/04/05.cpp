#include "binary_tree.hpp"

template <class T>
bool validate_BST(binary_tree<T> const& tree) {
  bool ok{true};
  if (tree.left()) ok = ok && tree.left()->value() <= tree.value() && validate_BST(*tree.left());
  if (tree.right()) ok = ok && tree.value() <= tree.right()->value() && validate_BST(*tree.right());
  return ok;
}
