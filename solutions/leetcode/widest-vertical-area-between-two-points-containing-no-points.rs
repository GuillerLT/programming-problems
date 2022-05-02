/* Problem widest-vertical-area-between-two-points-containing-no-points
 * https://www.leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points
 */

struct Solution;

impl Solution {
    pub fn max_width_of_vertical_area(mut points: Vec<Vec<i32>>) -> i32 {
        points.sort_unstable_by_key(|xy| xy[0]);
        points
            .windows(2)
            .map(|ab| ab[1][0] - ab[0][0])
            .max()
            .unwrap()
    }
}

pub fn main() {}
