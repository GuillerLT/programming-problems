/* Problem longest-palindrome
 * https://www.leetcode.com/problems/longest-palindrome
 */

struct Solution;

impl Solution {
	pub fn longest_palindrome(s: String) -> i32 {
		let mut freqs = [0; 256];
		for c in s.as_bytes() {
			freqs[usize::from(*c)] += 1;
		}
		freqs
			.into_iter()
			.fold(0, |l, freq| (l + (freq & !1)) | (freq & 1))
	}
}

fn main() {}
