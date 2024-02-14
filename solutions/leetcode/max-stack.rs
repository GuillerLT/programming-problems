/* Problem max-stack
 * https://www.leetcode.com/problems/max-stack
 */

struct MinStack {
	stack: Vec<i32>,
	stack_min_indexes: Vec<usize>,
}

impl MinStack {
	fn new() -> Self {
		MinStack {
			stack: Vec::new(),
			stack_min_indexes: Vec::new(),
		}
	}

	fn push(&mut self, val: i32) {
		if self.stack_min_indexes.is_empty()
			|| val < self.stack[*self.stack_min_indexes.last().unwrap()]
		{
			self.stack_min_indexes.push(self.stack.len());
		}
		self.stack.push(val);
	}

	fn pop(&mut self) {
		self.stack.pop().unwrap();
		if *self.stack_min_indexes.last().unwrap() >= self.stack.len() {
			self.stack_min_indexes.pop().unwrap();
		}
	}

	fn top(&self) -> i32 {
		*self.stack.last().unwrap()
	}

	fn get_min(&self) -> i32 {
		self.stack[*self.stack_min_indexes.last().unwrap()]
	}
}

pub fn main() {}
