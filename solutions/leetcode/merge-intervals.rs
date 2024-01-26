/* Problem merge-intervals
 * https://www.leetcode.com/problems/merge-intervals
 */

struct Solution;

impl Solution {
	pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
		intervals.sort_unstable_by_key(|interval| interval[0]);
		let mut intervals = intervals.into_iter();
		let Some(first) = intervals.next() else {
			return Vec::new();
		};
		intervals.fold(vec![first], |mut non_overlapping, current| {
			let last = non_overlapping.last_mut().unwrap();
			if current[0] <= last[1] {
				last[1] = i32::max(last[1], current[1]);
			} else {
				non_overlapping.push(current)
			}
			non_overlapping
		})
	}
}

pub fn main() {}
