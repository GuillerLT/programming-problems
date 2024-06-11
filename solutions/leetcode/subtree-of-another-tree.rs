/* Problem subtree-of-another-tree
 * https://www.leetcode.com/problems/subtree-of-another-tree
 */

fn eq(a: Option<Rc<RefCell<TreeNode>>>, b: Option<Rc<RefCell<TreeNode>>>) -> bool {
	match (a, b) {
		(Some(a), Some(b)) => {
			let a = a.borrow();
			let b = b.borrow();
			a.val == b.val
				&& eq(a.left.clone(), b.left.clone())
				&& eq(a.right.clone(), b.right.clone())
		}
		(None, None) => true,
		_ => false,
	}
}

impl Solution {
	pub fn is_subtree(
		root: Option<Rc<RefCell<TreeNode>>>,
		sub_root: Option<Rc<RefCell<TreeNode>>>,
	) -> bool {
		if eq(root.clone(), sub_root.clone()) {
			return true;
		}
		let Some(root) = root else { return false };
		let root = root.borrow();
		Self::is_subtree(root.left.clone(), sub_root.clone())
			|| Self::is_subtree(root.right.clone(), sub_root.clone())
	}
}

use std::cell::RefCell;
use std::rc::Rc;
struct Solution;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
	pub val: i32,
	pub left: Option<Rc<RefCell<TreeNode>>>,
	pub right: Option<Rc<RefCell<TreeNode>>>,
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

fn main() {}
