/* Problem lowest-common-ancestor-of-a-binary-tree
 * https://www.leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
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
	pub fn lowest_common_ancestor(
		root: Option<Rc<RefCell<TreeNode>>>,
		p: Option<Rc<RefCell<TreeNode>>>,
		q: Option<Rc<RefCell<TreeNode>>>,
	) -> Option<Rc<RefCell<TreeNode>>> {
		if let Found::Both(ancestor) = lowest_common_ancestor_impl(root, &p?, &q?) {
			Some(ancestor)
		} else {
			None
		}
	}
}

enum Found {
	Both(Rc<RefCell<TreeNode>>),
	One,
	None,
}

fn lowest_common_ancestor_impl(
	root: Option<Rc<RefCell<TreeNode>>>,
	p: &Rc<RefCell<TreeNode>>,
	q: &Rc<RefCell<TreeNode>>,
) -> Found {
	let Some(root) = root else {
		return Found::None;
	};
	let mut current_ancestor = if Rc::ptr_eq(&root, p) || Rc::ptr_eq(&root, q) {
		Found::One
	} else {
		Found::None
	};
	for subnode in [&root.borrow().left, &root.borrow().right] {
		match (
			lowest_common_ancestor_impl(subnode.clone(), p, q),
			&current_ancestor,
		) {
			(Found::Both(common_ancestor), _) => return Found::Both(common_ancestor),
			(Found::One, Found::One) => return Found::Both(root.clone()),
			(Found::One, _) => current_ancestor = Found::One,
			(Found::None, _) => {}
		}
	}
	current_ancestor
}

fn main() {}
