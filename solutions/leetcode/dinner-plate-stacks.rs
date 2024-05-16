/* Problem dinner-plate-stacks
 * https://www.leetcode.com/problems/dinner-plate-stacks
 */

struct DinnerPlates {
	capacity: usize,
	stacks: Vec<Vec<i32>>,
	next_stack: std::collections::BTreeSet<usize>,
}

impl DinnerPlates {
	fn new(capacity: i32) -> Self {
		assert!(capacity > 0);
		Self {
			capacity: capacity as usize,
			stacks: Default::default(),
			next_stack: Default::default(),
		}
	}

	fn push(&mut self, val: i32) {
		let index = self
			.next_stack
			.first()
			.copied()
			.unwrap_or_else(|| self.stacks.len());
		if index >= self.stacks.len() {
			self.stacks
				.resize_with(index + 1, || Vec::with_capacity(self.capacity));
		}
		let stack = &mut self.stacks[index];
		stack.push(val);
		self.add_index_if_needed(index);
	}

	fn pop(&mut self) -> i32 {
		self.pop_at_stack_usize(self.stacks.len() - 1)
	}

	fn pop_at_stack(&mut self, index: i32) -> i32 {
		self.pop_at_stack_usize(index as usize)
	}

	fn pop_at_stack_usize(&mut self, index: usize) -> i32 {
		let Some(stack) = self.stacks.get_mut(index) else {
			return -1;
		};
		let val = stack.pop().unwrap_or(-1);
		self.add_index_if_needed(index);
		self.remove_last_empties();
		val
	}

	fn add_index_if_needed(&mut self, index: usize) {
		let Some(stack) = self.stacks.get(index) else {
			return;
		};
		if stack.len() >= self.capacity {
			self.next_stack.remove(&index);
		} else {
			self.next_stack.insert(index);
		}
	}

	fn remove_last_empties(&mut self) {
		while self.stacks.last().is_some_and(|stack| stack.is_empty()) {
			let index = self.stacks.len() - 1;
			self.next_stack.remove(&index);
			self.stacks.pop();
		}
	}
}

fn main() {}
