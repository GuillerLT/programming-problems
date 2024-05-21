/* Problem construct-binary-tree-from-preorder-and-inorder-traversal
 * https://www.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 */

fn build_tree_impl<'a>(
	mut preorder: &'a [i32],
	inorder: &'a [i32],
) -> (Option<Rc<RefCell<TreeNode>>>, &'a [i32]) {
	let Some(next) = preorder.first() else {
		return (None, preorder);
	};
	let Some(i_inorder) = inorder
		.into_iter()
		.enumerate()
		.find_map(|(i, val)| (val == next).then_some(i))
	else {
		return (None, preorder);
	};
	let mut node = TreeNode::new(*next);
	(node.left, preorder) = build_tree_impl(&preorder[1..], &inorder[..i_inorder]);
	(node.right, preorder) = build_tree_impl(preorder, &inorder[(i_inorder + 1)..]);

	(Some(Rc::new(RefCell::new(node))), preorder)
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
	pub fn build_tree(preorder: Vec<i32>, inorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
		build_tree_impl(&preorder, &inorder).0
	}
}

fn main() {}
