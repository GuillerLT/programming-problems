/* Problem string-to-integer-atoi
 * https://www.leetcode.com/problems/string-to-integer-atoi
 */

struct Solution;

impl Solution {
	pub fn my_atoi(s: String) -> i32 {
		let s = s.trim_start();
		let (s, sign) = if s.starts_with('+') {
			(&s[1..], 1)
		} else if s.starts_with('-') {
			(&s[1..], -1)
		} else {
			(s, 1)
		};
		let mut num: i32 = 0;
		for c in s.chars() {
			let Some(digit) = c.to_digit(10) else {
				break;
			};
			num = num.saturating_mul(10).saturating_add(digit as i32 * sign);
		}
		num
	}
}

fn main() {
	println!("{}", Solution::my_atoi("   -42".to_string()));
}
