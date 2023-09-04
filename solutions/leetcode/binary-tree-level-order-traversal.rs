/* Problem binary-tree-level-order-traversal
 * https://www.leetcode.com/problems/binary-tree-level-order-traversal
 */

struct Solution;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
	pub val: i32,
	pub left: Option<Rc<RefCell<TreeNode>>>,
	pub right: Option<Rc<RefCell<TreeNode>>>,
}

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
	pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
		let mut remaining = std::collections::VecDeque::from_iter(root.map(|node| (0, node)));
		let mut levels = vec![];
		while let Some((depth, node)) = remaining.pop_front() {
			if depth >= levels.len() {
				levels.push(vec![]);
			}
			let node = node.borrow();
			levels.last_mut().unwrap().push(node.val);
			remaining.extend(node.left.clone().map(|node| (depth + 1, node)));
			remaining.extend(node.right.clone().map(|node| (depth + 1, node)));
		}
		levels
	}
}

pub fn main() {}
