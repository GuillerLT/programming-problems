/* Problem valid-palindrome
 * https://www.leetcode.com/problems/valid-palindrome
 */

struct Solution;

impl Solution {
	pub fn is_palindrome(s: String) -> bool {
		let s = s
			.chars()
			.filter(|c| c.is_alphanumeric())
			.map(|c| c.to_ascii_lowercase());
		s.clone().rev().eq(s)
	}
}

pub fn main() {}
