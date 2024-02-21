/* Problem unique-paths
 * https://www.leetcode.com/problems/unique-paths
 */

struct Solution;

// b! / a!
fn div_factorial(a: u128, b: u128) -> u128 {
	(a..=b).fold(1, |i, j| i * j)
}

impl Solution {
	fn unique_paths_math(m: i32, n: i32) -> i32 {
		let (m, n) = (i32::max(m, n) as u128 - 1, i32::min(m, n) as u128 - 1);
		(div_factorial(m + 1, m + n) / div_factorial(1, n)) as i32
	}

	fn unique_paths_dp(m: i32, n: i32) -> i32 {
		let (height, width) = (m as usize, n as usize);
		let mut dp = vec![0; height * width];
		dp[0..width].fill(1); // fill first row (unique path)
		for row in 1..height {
			// fill first column (unique path)
			dp[row * width] = 1;
		}
		for row in 1..height {
			for column in 1..width {
				dp[row * width + column] =
					dp[row * width + column - width] + dp[row * width + column - 1]
			}
		}
		dp[height * width - 1]
	}

	pub fn unique_paths(m: i32, n: i32) -> i32 {
		Self::unique_paths_dp(m, n)
	}
}

fn main() {
	println!("{}", Solution::unique_paths(3, 7));
	println!("{}", Solution::unique_paths(3, 2));
	println!("{}", Solution::unique_paths(23, 12));
	println!("{}", Solution::unique_paths(16, 16));
}
