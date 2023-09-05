/* Problem product-of-array-except-self
 * https://www.leetcode.com/problems/product-of-array-except-self
 */

struct Solution;

impl Solution {
	pub fn product_except_self(mut nums: Vec<i32>) -> Vec<i32> {
		let (exist_zero, product) =
			nums.iter()
				.fold((false, 1i32), |(exist_zero, product), num| {
					if *num == 0 && !exist_zero {
						(true, product)
					} else {
						(exist_zero, product * num)
					}
				});

		for num in &mut nums {
			*num = if *num == 0 {
				product
			} else if exist_zero {
				0
			} else {
				product / *num
			};
		}

		nums
	}
}

pub fn main() {
	assert_eq!(
		vec![24, 12, 8, 6],
		Solution::product_except_self(vec![1, 2, 3, 4])
	);
	assert_eq!(
		vec![0, 0, 9, 0, 0],
		Solution::product_except_self(vec![-1, 1, 0, -3, 3])
	);
}
