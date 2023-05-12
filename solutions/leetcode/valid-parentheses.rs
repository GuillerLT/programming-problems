/* Problem valid-parentheses
 * https://www.leetcode.com/problems/valid-parentheses
 */

struct Solution;

impl Solution {
	pub fn is_valid(s: String) -> bool {
		let (stack, ok) = s
			.chars()
			.fold((Vec::new(), true), |(mut stack, mut ok), i| {
				match i {
					'(' | '{' | '[' => stack.push(i),
					')' | '}' | ']' => {
						ok = ok
							&& stack
								.pop()
								.map(|j| match (j, i) {
									('(', ')') | ('{', '}') | ('[', ']') => true,
									_ => false,
								})
								.unwrap_or(false)
					}
					_ => panic!(),
				};
				(stack, ok)
			});
		ok && stack.is_empty()
	}
}

pub fn main() {}
