/* Problem ransom-note
 * https://www.leetcode.com/problems/ransom-note
 */

struct Solution;

impl Solution {
	pub fn can_construct(ransom_note: String, magazine: String) -> bool {
		let mut freqs = [0; 26];
		for c in magazine.as_bytes() {
			freqs[usize::from(*c) - 97] += 1;
		}
		for c in ransom_note.as_bytes() {
			freqs[usize::from(*c) - 97] -= 1;
		}
		freqs.into_iter().all(|freq| freq >= 0)
	}
}

fn main() {}
