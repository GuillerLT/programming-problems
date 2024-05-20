/* Problem validate-binary-search-tree
 * https://www.leetcode.com/problems/validate-binary-search-tree
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

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
	pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
		is_valid_bst_impl(root, None, None)
	}
}

fn is_valid_bst_impl(
	root: Option<Rc<RefCell<TreeNode>>>,
	lower: Option<i32>,
	upper: Option<i32>,
) -> bool {
	let Some(root) = root else { return true };
	let val = root.borrow().val;
	lower.map_or(true, |lower| val > lower)
		&& upper.map_or(true, |upper| val < upper)
		&& is_valid_bst_impl(root.borrow().left.clone(), lower, Some(val))
		&& is_valid_bst_impl(root.borrow().right.clone(), Some(val), upper)
}

fn main() {}
