/* Problem path-sum-iii
 * https://www.leetcode.com/problems/path-sum-iii
 */

fn path_sum_impl(
	root: Option<Rc<RefCell<TreeNode>>>,
	target_sum: i64,
	previous_sum: i64,
	sums: &mut std::collections::BTreeMap<i64, i64>,
) -> i64 {
	let Some(root) = root else { return 0 };
	let root = root.borrow();
	let current_sum = previous_sum + root.val as i64;
	let delta = current_sum - target_sum;
	let cnt = sums.get(&delta).copied().unwrap_or(0);
	*sums.entry(current_sum).or_insert(0) += 1;
	let cnt = cnt
		+ path_sum_impl(root.left.clone(), target_sum, current_sum, sums)
		+ path_sum_impl(root.right.clone(), target_sum, current_sum, sums);
	*sums.entry(current_sum).or_insert(0) -= 1;
	return cnt;
}

impl Solution {
	pub fn path_sum(root: Option<Rc<RefCell<TreeNode>>>, target_sum: i32) -> i32 {
		let mut sums = std::collections::BTreeMap::from_iter([(0, 1)]);
		path_sum_impl(root, target_sum as i64, 0, &mut sums) as i32
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
