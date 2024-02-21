/* Problem longest-palindromic-substring
 * https://www.leetcode.com/problems/longest-palindromic-substring
 */

struct Solution;

impl Solution {
	pub fn longest_palindrome(s: String) -> String {
		let s = s.as_bytes();
		let n = s.len();
		let mut is_palindrome = vec![false; n * n];
		is_palindrome[0] = true;
		for i in 1..n {
			is_palindrome[i + i * n] = true;
			is_palindrome[i + i * n - n] = true;
		}
		let mut max_j = 0;
		let mut max_k = 0;
		for i in 1..n {
			for j in 0..(n - i) {
				let k = j + i;
				is_palindrome[j + k * n] = s[j] == s[k] && is_palindrome[(j + 1) + (k - 1) * n];
				if is_palindrome[j + k * n] {
					max_j = j;
					max_k = k;
				}
			}
		}

		String::from_utf8(s[max_j..=max_k].to_vec()).unwrap()
	}
}

fn main() {}
