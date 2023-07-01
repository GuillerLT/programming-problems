/* Problem longest-substring-without-repeating-characters
 * https://www.leetcode.com/problems/longest-substring-without-repeating-characters
 */

struct Solution;

impl Solution {
	pub fn length_of_longest_substring(s: String) -> i32 {
		let first = s.as_bytes().first().cloned();
		s.into_bytes()
			.into_iter()
			.chain(first)
			.enumerate()
			.fold(
				(0, 0, [usize::MAX; 256]),
				|(mut max_length, mut left, mut last_indexes), (index, byte)| {
					let last_index = &mut last_indexes[usize::from(byte)];
					if *last_index < index {
						max_length = usize::max(max_length, index - left);
						left = usize::max(left, *last_index + 1);
					}
					*last_index = index;
					(max_length, left, last_indexes)
				},
			)
			.0
			.try_into()
			.unwrap()
	}
}

pub fn main() {}
