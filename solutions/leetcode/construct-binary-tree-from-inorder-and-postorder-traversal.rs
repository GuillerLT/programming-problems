/* Problem construct-binary-tree-from-inorder-and-postorder-traversal
 * https://www.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 */

fn build_tree_impl<'a>(
	inorder: &'a [i32],
	mut postorder: &'a [i32],
) -> (Option<Rc<RefCell<TreeNode>>>, &'a [i32]) {
	let Some(next) = postorder.last() else {
		return (None, postorder);
	};
	let Some(i_inorder) = inorder
		.into_iter()
		.enumerate()
		.find_map(|(i, val)| (val == next).then_some(i))
	else {
		return (None, postorder);
	};
	let mut node = TreeNode::new(*next);
	(node.right, postorder) = build_tree_impl(
		&inorder[(i_inorder + 1)..],
		&postorder[..postorder.len() - 1],
	);
	(node.left, postorder) = build_tree_impl(&inorder[..i_inorder], postorder);

	(Some(Rc::new(RefCell::new(node))), postorder)
}

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

use std::cell::RefCell;
use std::rc::Rc;

struct Solution;
impl Solution {
	pub fn build_tree(inorder: Vec<i32>, postorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
		build_tree_impl(&inorder, &postorder).0
	}
}

fn main() {
	dbg!(Solution::build_tree(
		vec![9, 3, 15, 20, 7],
		vec![9, 15, 7, 20, 3]
	));
}
