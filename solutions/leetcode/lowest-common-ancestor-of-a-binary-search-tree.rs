/* Problem lowest-common-ancestor-of-a-binary-search-tree
 * https://www.leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
 */

struct Solution;

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
	pub val: i32,
	pub left: Option<Rc<RefCell<TreeNode>>>,
	pub right: Option<Rc<RefCell<TreeNode>>>,
}

use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
	pub fn lowest_common_ancestor(
		mut root: Option<Rc<RefCell<TreeNode>>>,
		p: Option<Rc<RefCell<TreeNode>>>,
		q: Option<Rc<RefCell<TreeNode>>>,
	) -> Option<Rc<RefCell<TreeNode>>> {
		let p = p.unwrap().borrow().val;
		let q = q.unwrap().borrow().val;
		let (p, q) = if p < q { (p, q) } else { (q, p) };

		loop {
			let r = root.clone().unwrap().borrow().val;
			if p < r && q < r {
				root = root.unwrap().borrow().left.clone();
			} else if p > r && q > r {
				root = root.unwrap().borrow().right.clone();
			} else {
				break root;
			}
		}
	}
}

pub fn main() {}
