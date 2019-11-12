#include <iostream>
#include <tuple>
#include <vector>

template <typename RandomAccessContainer, typename Manipulator>
class segment_tree {
  using Value = decltype(std::declval<Manipulator>().identity());

 private:
  Manipulator manipulator;
  size_t const size;
  std::vector<Value> values;

  Value const& compute(size_t const l, size_t const r, size_t const i,
                       RandomAccessContainer const& randomAccessContainer) {
    Value& value = values[i];
    if (l == r) {
      value = manipulator.query(randomAccessContainer[l]);
    } else {
      size_t const m = l + (r - l) / 2;
      value = manipulator.query(
          compute(l, m, i * 2 + 1, randomAccessContainer),
          compute(m + 1, r, i * 2 + 2, randomAccessContainer));
    }
    return value;
  }

  Value query(size_t const l, size_t const r, size_t const i,
              size_t const lquery, size_t const rquery) const {
    if (lquery <= l && rquery >= r) {
      return values[i];
    } else if (rquery < l || lquery > r) {
      return manipulator.identity();
    } else {
      size_t const m = l + (r - l) / 2;
      return manipulator.query(query(l, m, i * 2 + 1, lquery, rquery),
                               query(m + 1, r, i * 2 + 2, lquery, rquery));
    }
  }

 public:
  segment_tree(RandomAccessContainer const& randomAccessContainer,
               Manipulator const& manipulator)
      : manipulator(manipulator), size(randomAccessContainer.size() - 1) {
    values.resize((size + 1) << 2);
    compute(0, size, 0, randomAccessContainer);
  }

  Value query(size_t const lquery, size_t const rquery) const {
    return query(0, size, 0, lquery, rquery);
  }
};

using namespace std;

class segment_tree_manipulator {
 public:
  tuple<int, int, int> query(char const& input) const {
    tuple<int, int, int> tiii;
    get<0>(tiii) = 0;
    if (input == '(') {
      get<1>(tiii) = 1;
      get<2>(tiii) = 0;
    } else {
      get<1>(tiii) = 0;
      get<2>(tiii) = 1;
    }
    return tiii;
  }
  tuple<int, int, int> query(tuple<int, int, int> const& tiii1,
                             tuple<int, int, int> const& tiii2) const {
    tuple<int, int, int> tiii;
    int const tmp = min(get<1>(tiii1), get<2>(tiii2));
    get<0>(tiii) = get<0>(tiii1) + get<0>(tiii2) + 2 * tmp;
    get<1>(tiii) = get<1>(tiii1) + get<1>(tiii2) - tmp;
    get<2>(tiii) = get<2>(tiii1) + get<2>(tiii2) - tmp;
    return tiii;
  }
  tuple<int, int, int> identity() const { return make_tuple(0, 0, 0); }
};

int main() {
  string s;
  cin >> s;
  segment_tree st(s, segment_tree_manipulator());
  int n;
  cin >> n;
  while (--n >= 0) {
    size_t l, r;
    cin >> l >> r;
    cout << get<0>(st.query(l - 1, r - 1)) << '\n';
  }

  return 0;
}