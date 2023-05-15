/* Problem implement-queue-using-stacks
 * https://www.leetcode.com/problems/implement-queue-using-stacks
 */

struct MyQueue {
	stack1: Vec<i32>,
	stack2: Vec<i32>,
}

impl MyQueue {
	fn new() -> Self {
		Self {
			stack1: Vec::new(),
			stack2: Vec::new(),
		}
	}

	fn push(&mut self, x: i32) {
		self.stack1.push(x)
	}

	fn pop(&mut self) -> i32 {
		if self.stack2.is_empty() {
			self.stack2.extend(self.stack1.drain(..).rev())
		}
		self.stack2.pop().unwrap()
	}

	fn peek(&mut self) -> i32 {
		if self.stack2.is_empty() {
			self.stack2.extend(self.stack1.drain(..).rev())
		}
		self.stack2.last().unwrap().to_owned()
	}

	fn empty(&mut self) -> bool {
		self.stack1.is_empty() && self.stack2.is_empty()
	}
}

pub fn main() {}
