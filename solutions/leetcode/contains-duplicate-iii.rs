/* Problem contains-duplicate-iii
 * https://www.leetcode.com/problems/contains-duplicate-iii
 */

struct Solution;

impl Solution {
    pub fn contains_nearby_almost_duplicate(nums: Vec<i32>, k: i32, t: i32) -> bool {
        if k <= 0 || t < 0 {
            return false;
        }
        let k = k as i64;
        let t = t as i64;
        let mut numbers_fifo = std::collections::VecDeque::<i64>::default();
        let mut numbers_set = std::collections::BTreeSet::<i64>::default();
        let mut numbers_count = 0;
        for num in nums {
            let num = num as i64;
            if numbers_set.range((num - t)..=(num + t)).count() > 0 {
                return true;
            }
            if !numbers_set.insert(num) {
                numbers_fifo.remove(
                    numbers_fifo
                        .iter()
                        .enumerate()
                        .find(|(_, n)| **n == num)
                        .unwrap()
                        .0,
                );
            }
            numbers_fifo.push_back(num);
            if numbers_count == k {
                let target = numbers_fifo.pop_front().unwrap();
                numbers_set.remove(&target);
            } else {
                numbers_count += 1;
            }
        }
        false
    }
}


pub fn main() {
}
