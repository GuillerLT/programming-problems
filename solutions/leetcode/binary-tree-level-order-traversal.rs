/* Problem binary-tree-level-order-traversal
 * https://www.leetcode.com/problems/binary-tree-level-order-traversal
 */

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
	pub val: i32,
	pub left: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
	pub right: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
}

impl TreeNode {
	#[inline]
	pub fn new(val: i32) -> Self {
		TreeNode {
			val,
			left: None,
			right: None,
		}
	}
}

struct Solution;

impl Solution {
	pub fn level_order(root: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
		let mut level = vec![root];
		let mut level_values = vec![];
		loop {
			let mut values = Vec::with_capacity(level.len());
			let mut next_level = Vec::with_capacity(level.len() * 2);
			for node in level.drain(..).flatten() {
				let node = node.borrow();
				values.push(node.val);
				next_level.push(node.left.clone());
				next_level.push(node.right.clone());
			}
			if values.is_empty() {
				break;
			}
			level_values.push(values);
			level.append(&mut next_level);
		}
		level_values
	}
}

fn main() {}
