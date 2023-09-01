/* Problem invert-binary-tree
 * https://www.leetcode.com/problems/invert-binary-tree
 */

struct Solution;

use std::cell::RefCell;
use std::rc::Rc;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
	pub val: i32,
	pub left: Option<Rc<RefCell<TreeNode>>>,
	pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl Solution {
	pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
		root.map(|rootc| {
			let mut root = rootc.borrow_mut();

			let new_right = Self::invert_tree(root.left.take());
			let new_left = Self::invert_tree(root.right.take());

			root.left = new_left;
			root.right = new_right;
			drop(root);

			rootc
		})
	}
}

pub fn main() {}
