/* Problem word-break
 * https://www.leetcode.com/problems/word-break
 */

struct Solution;

impl Solution {
	pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
		let mut mems = vec![None; s.len() + 1];
		mems[0] = Some(true);
		Self::word_break_impl(&s, &word_dict, &mut mems)
	}

	fn word_break_impl(str: &str, word_dict: &[String], mems: &mut [Option<bool>]) -> bool {
		let (mems, mem) = mems.split_at_mut(str.len());
		let mem = &mut mem[0];
		if let Some(mem) = mem {
			return *mem;
		};
		for word in word_dict {
			if let Some(str) = str.strip_prefix(word) {
				if Self::word_break_impl(str, word_dict, mems) {
					*mem = Some(true);
					return true;
				}
			}
		}
		*mem = Some(false);
		false
	}
}

pub fn main() {}
