/* Problem merge-two-sorted-lists
 * https://www.leetcode.com/problems/merge-two-sorted-lists
 */

struct Solution;

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
	pub val: i32,
	pub next: Option<Box<ListNode>>,
}

impl Solution {
	pub fn merge_two_lists(
		mut list1: Option<Box<ListNode>>,
		mut list2: Option<Box<ListNode>>,
	) -> Option<Box<ListNode>> {
		let mut node_root = ListNode { val: 0, next: None };
		let mut node_last: &mut ListNode = &mut node_root;

		loop {
			let (mut node_least, list_greatest) = match (list1.take(), list2.take()) {
				(Some(n1), Some(n2)) => {
					if n1.val < n2.val {
						(n1, Some(n2))
					} else {
						(n2, Some(n1))
					}
				}
				(Some(n), None) | (None, Some(n)) => (n, None),
				(None, None) => break,
			};
			list1 = node_least.next.take();
			list2 = list_greatest;
			node_last = node_last.next.insert(node_least).as_mut();
		}

		node_root.next
	}
}

pub fn main() {}
