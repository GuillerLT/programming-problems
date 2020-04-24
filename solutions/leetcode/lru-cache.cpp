/* Problem lru-cache
 * https://www.leetcode.com/problems/lru-cache
 */

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
 private:
  size_t const capacity;
  list<pair<int, int>> cache;
  unordered_map<int, list<pair<int, int>>::const_iterator> index;

 public:
  LRUCache(int const capacity) : capacity{static_cast<size_t>(capacity)} {}

  int get(int const key) {
    auto const entry = index.find(key);
    if (entry != index.cend()) {
      int const value = entry->second->second;
      cache.erase(entry->second);
      cache.emplace_back(make_pair(key, value));
      return value;
    } else {
      return -1;
    }
  }

  void put(int const key, int const value) {
    cache.emplace_back(make_pair(key, value));
    auto const it = prev(cache.cend());
    auto const entry = index.emplace(make_pair(key, it));
    if (!entry.second) {
      cache.erase(entry.first->second);
      entry.first->second = it;
    } else if (cache.size() > capacity) {
      index.erase(cache.front().first);
      cache.pop_front();
    }
  }
};
