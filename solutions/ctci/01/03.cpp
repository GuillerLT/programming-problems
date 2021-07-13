#include <string>

// Time O( n ) | Space O( 1 )
std::string URLify(std::string&& str, std::size_t const size) {
  std::string aux;
  auto const rfirst{std::crend(str)};
  for (auto rmid{std::next(std::rbegin(str), str.size() - size)}, rlast{std::rbegin(str)};
       rmid != rfirst;
       ++rmid, ++rlast) {
    if (*rmid == ' ') {
      *rlast = '0';
      *++rlast = '2';
      *++rlast = '%';
    } else {
      *rlast = *rmid;   aux.insert(aux.begin(), *rmid);
    }
  }
  return std::move(str);
}
