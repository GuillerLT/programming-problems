/* Problem search-in-rotated-sorted-array
 * https://www.leetcode.com/problems/search-in-rotated-sorted-array
 */

struct Solution;

impl Solution {
	fn find_pivot(nums: &[i32]) -> usize {
		if nums.len() <= 1 {
			return 0;
		}

		let mid = nums.len() / 2;
		if nums
			.get(mid)
			.zip(nums.get(mid + 1))
			.map_or(false, |(a, b)| a > b)
		{
			mid + 1
		} else {
			if *nums.last().unwrap() > nums[mid] {
				Self::find_pivot(&nums[..=mid])
			} else {
				Self::find_pivot(&nums[mid..]) + mid
			}
		}
	}

	pub fn search(nums: Vec<i32>, target: i32) -> i32 {
		let pivot = Self::find_pivot(&nums);

		let (l, r) = nums.split_at(pivot);

		l.binary_search(&target)
			.or(r.binary_search(&target).map(|index| index + pivot))
			.map(|index| index.try_into().unwrap())
			.unwrap_or(-1)
	}
}

pub fn main() {
	assert_eq!(4, Solution::search(vec![4, 5, 6, 7, 0, 1, 2], 0));
	assert_eq!(-1, Solution::search(vec![4, 5, 6, 7, 0, 1, 2], 3));
	assert_eq!(-1, Solution::search(vec![1], 0));
	assert_eq!(1, Solution::search(vec![3, 5, 1], 5));
	assert_eq!(0, Solution::search(vec![5, 1, 3], 5));
}
