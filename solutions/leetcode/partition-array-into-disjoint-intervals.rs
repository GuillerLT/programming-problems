/* Problem partition-array-into-disjoint-intervals
 * https://www.leetcode.com/problems/partition-array-into-disjoint-intervals
 */

struct Solution;

impl Solution {
    pub fn partition_disjoint(nums: Vec<i32>) -> i32 {
        let f = nums
            .iter()
            .scan(0, |max, num|{
              *max = std::cmp::max(*max, *num);
              Some(*max)
            });
        let b = nums
            .iter()
            .rev()
            .scan(1000001, |min, num|{
              *min = std::cmp::min(*min, *num);
              Some(*min)
            })
            .collect::<Vec<i32>>();
        f.zip(b.iter().rev().skip(1))
          .enumerate()
          .find(|(_, (maxf, minb))|{
            maxf <= minb
          }).unwrap().0 as i32 + 1
    }
}
