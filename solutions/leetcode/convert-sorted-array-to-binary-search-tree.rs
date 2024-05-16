/* Problem convert-sorted-array-to-binary-search-tree
 * https://www.leetcode.com/problems/convert-sorted-array-to-binary-search-tree
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

impl Solution {
	pub fn sorted_array_to_bst(
		nums: Vec<i32>,
	) -> Option<std::rc::Rc<std::cell::RefCell<TreeNode>>> {
		sort_array_to_bst_impl(&nums)
	}
}

fn sort_array_to_bst_impl(nums: &[i32]) -> Option<std::rc::Rc<std::cell::RefCell<TreeNode>>> {
	let len = nums.len();
	if len == 0 {
		return None;
	}
	let mid = len / 2;
	let mut node = TreeNode::new(nums[mid]);
	node.left = sort_array_to_bst_impl(&nums[0..mid]);
	node.right = sort_array_to_bst_impl(&nums[mid + 1..len]);
	Some(std::rc::Rc::new(std::cell::RefCell::new(node)))
}

fn main() {}
