/* Problem validate-binary-search-tree
 * https://www.leetcode.com/problems/validate-binary-search-tree
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
	fn is_valid_bst_impl(
		root: &Option<Rc<RefCell<TreeNode>>>,
		lower_boud: i64,
		upper_bound: i64,
	) -> bool {
		root.as_ref().map_or(true, |node| {
			let node = node.borrow();
			let val = node.val.into();
			val > lower_boud
				&& val < upper_bound
				&& Self::is_valid_bst_impl(&node.left, lower_boud, val)
				&& Self::is_valid_bst_impl(&node.right, val, upper_bound)
		})
	}

	pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
		Self::is_valid_bst_impl(&root, i64::MIN, i64::MAX)
	}
}

pub fn main() {}
