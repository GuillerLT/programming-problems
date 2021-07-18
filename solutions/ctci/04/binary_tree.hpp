#pragma once

#include <memory>

template <class T>
class binary_tree {
 public:
  binary_tree() = default;
  binary_tree(binary_tree&&) = default;
  binary_tree& operator=(binary_tree&&) = default;
  ~binary_tree() = default;

  template <class V>
  binary_tree(V&& value,
              std::unique_ptr<binary_tree<T>>&& left,
              std::unique_ptr<binary_tree<T>>&& right)
      : value_{std::forward<V>(value)},
        left_{std::move(left)},
        right_{std::move(right)} {}

  T      & value()      & { return value_; }
  T const& value() const& { return value_; }
  T     && value()     && { return std::move(value_); }

  std::unique_ptr<binary_tree<T>>      & left()      & { return left_; }
  std::unique_ptr<binary_tree<T>> const& left() const& { return left_; }
  std::unique_ptr<binary_tree<T>>     && left()     && { return std::move(left_); }

  std::unique_ptr<binary_tree<T>>      & right()      & { return right_; }
  std::unique_ptr<binary_tree<T>> const& right() const& { return right_; }
  std::unique_ptr<binary_tree<T>>     && right()     && { return std::move(right_); }

 private:
  T value_;
  std::unique_ptr<binary_tree<T>> left_, right_;
};