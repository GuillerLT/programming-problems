/* Problem search-in-a-binary-search-tree
 * https://www.leetcode.com/problems/search-in-a-binary-search-tree
 */

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
      right: None
    }
  }
}
struct Solution;

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
  pub fn search_bst(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> Option<Rc<RefCell<TreeNode>>> {
    root.and_then(|root| {
      if root.as_ref().borrow().val == val {
        Some(root.clone())
      } else {
        Solution::search_bst(root.as_ref().borrow().left.clone(), val)
        .or(Solution::search_bst(root.as_ref().borrow().right.clone(), val))
      }
    })
  }
}
