/* Problem balanced-binary-tree
 * https://www.leetcode.com/problems/balanced-binary-tree
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
	pub fn is_balanced(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
		is_balanced_impl(root).is_some()
	}
}

fn is_balanced_impl(root: Option<Rc<RefCell<TreeNode>>>) -> Option<usize> {
	let Some(root) = root.map(|root| Rc::into_inner(root).unwrap().into_inner()) else {
		return Some(0);
	};
	let height_l = is_balanced_impl(root.left)?;
	let height_r = is_balanced_impl(root.right)?;
	(usize::abs_diff(height_l, height_r) <= 1).then_some(usize::max(height_l, height_r) + 1)
}

fn main() {}
