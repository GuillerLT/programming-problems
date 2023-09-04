/* Problem evaluate-reverse-polish-notation
 * https://www.leetcode.com/problems/evaluate-reverse-polish-notation
 */

struct Solution;

impl Solution {
	pub fn eval_rpn(tokens: Vec<String>) -> i32 {
		let mut stack = Vec::with_capacity(tokens.len() / 2);
		for token in tokens {
			match token.as_str() {
				"+" => {
					let b = stack.pop().unwrap();
					let a = stack.pop().unwrap();
					stack.push(a + b);
				}
				"-" => {
					let b = stack.pop().unwrap();
					let a = stack.pop().unwrap();
					stack.push(a - b);
				}
				"*" => {
					let b = stack.pop().unwrap();
					let a = stack.pop().unwrap();
					stack.push(a * b);
				}
				"/" => {
					let b = stack.pop().unwrap();
					let a = stack.pop().unwrap();
					stack.push(a / b);
				}
				token => {
					stack.push(token.parse().unwrap());
				}
			}
		}
		let [ans] = *stack.into_boxed_slice() else {
			panic!()
		};
		ans
	}
}

pub fn main() {
	assert_eq!(
		9,
		Solution::eval_rpn(vec![
			"2".to_string(),
			"1".to_string(),
			"+".to_string(),
			"3".to_string(),
			"*".to_string(),
		])
	);

	assert_eq!(
		6,
		Solution::eval_rpn(vec![
			"4".to_string(),
			"13".to_string(),
			"5".to_string(),
			"/".to_string(),
			"+".to_string(),
		])
	);

	assert_eq!(
		22,
		Solution::eval_rpn(vec![
			"10".to_string(),
			"6".to_string(),
			"9".to_string(),
			"3".to_string(),
			"+".to_string(),
			"-11".to_string(),
			"*".to_string(),
			"/".to_string(),
			"*".to_string(),
			"17".to_string(),
			"+".to_string(),
			"5".to_string(),
			"+".to_string(),
		])
	);
}
