/* Problem keys-and-rooms
 * https://www.leetcode.com/problems/keys-and-rooms
 */

#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    unordered_set<size_t> visited{}, available{0};
    while (!available.empty()) {
      size_t const i{available.extract(available.begin()).value()};
      if (!visited.count(i)) {
        visited.insert(i);
        for (int const room : rooms[i]) {
          if (!visited.count(room)) {
            available.insert(room);
          }
        }
      }
    }
    return visited.size() == rooms.size();
  }
};
