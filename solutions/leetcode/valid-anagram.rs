/* Problem valid-anagram
 * https://www.leetcode.com/problems/valid-anagram
 */

struct Solution;

impl Solution {
	pub fn is_anagram(s: String, t: String) -> bool {
		if s.len() != t.len() {
			return false;
		}
		let mut freqs = [0; 26];
		for c in s.as_bytes() {
			freqs[usize::from(*c) - 97] += 1;
		}
		for c in t.as_bytes() {
			freqs[usize::from(*c) - 97] -= 1;
		}
		freqs.into_iter().all(|freq| freq == 0)
	}
}
pub fn main() {}
