/* Problem k-closest-points-to-origin
 * https://www.leetcode.com/problems/k-closest-points-to-origin
 */

struct Solution;

impl Solution {
	pub fn k_closest(mut points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
		points.sort_by_cached_key(|point| {
			i64::pow(i64::from(point[0]), 2) + i64::pow(i64::from(point[1]), 2)
		});
		points.resize_with(usize::try_from(k).unwrap(), || Vec::default());
		points
	}
}

pub fn main() {}
