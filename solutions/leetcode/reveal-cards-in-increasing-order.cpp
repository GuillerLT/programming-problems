/* Problem reveal-cards-in-increasing-order
 * https://www.leetcode.com/problems/reveal-cards-in-increasing-order
 */

#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
    std::sort(std::begin(deck), std::end(deck));
    std::deque<std::size_t> indices(deck.size());
    std::iota(std::begin(indices), std::end(indices), 0);
    std::queue<std::size_t, std::deque<std::size_t>> simulator{std::move(indices)};
    std::vector<int> sol(deck.size());
    for (std::size_t i = 0; !simulator.empty(); ++i) {
      sol[simulator.front()] = deck[i];
      simulator.pop();
      if (!simulator.empty()) {
        simulator.push(simulator.front());
        simulator.pop();
      }
    }
    return sol;
  }
};