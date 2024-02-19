/* Problem binary-tree-right-side-view
 * https://www.leetcode.com/problems/binary-tree-right-side-view
 */

use std::cell::RefCell;
use std::rc::Rc;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
	pub val: i32,
	pub left: Option<Rc<RefCell<TreeNode>>>,
	pub right: Option<Rc<RefCell<TreeNode>>>,
}

struct Solution;

impl Solution {
	pub fn right_side_view(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
		let Some(root) = root else {
			return vec![];
		};
		let root = root.borrow();

		let left = Self::right_side_view(root.left.clone());
		let right = Self::right_side_view(root.right.clone());
		let mut view = vec![0; usize::max(left.len(), right.len()) + 1];
		view[0] = root.val;

		view[1..(right.len() + 1)].copy_from_slice(&right);
		view[(right.len() + 1)..].copy_from_slice(&left[usize::min(left.len(), right.len())..]);
		view
	}
}

fn main() {}
