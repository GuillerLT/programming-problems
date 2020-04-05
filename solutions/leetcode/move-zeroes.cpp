/* Problem move-zeroes
 * https://www.leetcode.com/problems/move-zeroes
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
    }
};
