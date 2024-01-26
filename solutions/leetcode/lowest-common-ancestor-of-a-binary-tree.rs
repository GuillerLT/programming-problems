/* Problem lowest-common-ancestor-of-a-binary-tree
 * https://www.leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
 */

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

use std::borrow::Borrow;
use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
	pub fn lowest_common_ancestor(
		root: Option<Rc<RefCell<TreeNode>>>,
		p: Option<Rc<RefCell<TreeNode>>>,
		q: Option<Rc<RefCell<TreeNode>>>,
	) -> Option<Rc<RefCell<TreeNode>>> {
		root.and_then(|r| {
			let rr = RefCell::borrow(&r).val;
			let pp = RefCell::borrow(p.as_ref().unwrap()).val;
			let qq = RefCell::borrow(q.as_ref().unwrap()).val;

			if rr == pp || rr == qq {
				return Some(r);
			}

			let a = Self::lowest_common_ancestor(
				RefCell::borrow(&r).left.clone(),
				p.clone(),
				q.clone(),
			);
			let b = Self::lowest_common_ancestor(
				RefCell::borrow(&r).right.clone(),
				p.clone(),
				q.clone(),
			);

			match (a, b) {
				(Some(_), Some(_)) => Some(r),
				(Some(a), None) => Some(a),
				(None, Some(b)) => Some(b),
				(None, None) => None,
			}
		})
	}
}

pub fn main() {}
