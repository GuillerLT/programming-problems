/* Problem number-of-ways-to-reorder-array-to-get-same-bst
 * https://www.leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst
 */

const MODULO: u64 = 1_000_000_000 + 7;

#[derive(Debug, PartialEq, Eq)]
pub struct MyTreeNode {
	pub val: i32,
	pub left: Option<Box<MyTreeNode>>,
	pub right: Option<Box<MyTreeNode>>,
}

impl MyTreeNode {
	#[inline]
	pub fn new(val: i32) -> Self {
		Self {
			val,
			left: None,
			right: None,
		}
	}

	pub fn insert(&mut self, val: i32) {
		let subnode = match self.val.cmp(&val) {
			std::cmp::Ordering::Less => &mut self.left,
			std::cmp::Ordering::Greater => &mut self.right,
			std::cmp::Ordering::Equal => panic!(),
		};
		if let Some(subnode) = subnode {
			subnode.insert(val);
		} else {
			*subnode = Some(Box::new(Self::new(val)));
		}
	}

	pub fn num_of_ways_and_count(&self, pascal_triangle: &[u64]) -> (u64, usize) {
		let (l, lc) = self
			.left
			.as_ref()
			.map_or((1, 0), |left| left.num_of_ways_and_count(pascal_triangle));
		let (r, rc) = self
			.right
			.as_ref()
			.map_or((1, 0), |right| right.num_of_ways_and_count(pascal_triangle));
		let comb = pascal_triangle[triangular_number(lc + rc) + lc];
		(((l * r) % MODULO * comb) % MODULO, lc + rc + 1)
	}
}

struct Solution;

impl Solution {
	pub fn num_of_ways(nums: Vec<i32>) -> i32 {
		let pascal_triangle = compute_pascal_triange(nums.len());
		let mut nums = nums.into_iter();
		let Some(mut root) = nums.next().map(MyTreeNode::new) else {
			return 0;
		};
		let root = {
			nums.for_each(|num| root.insert(num));
			root
		};
		(root.num_of_ways_and_count(&pascal_triangle).0 - 1) as i32
	}
}

fn triangular_number(n: usize) -> usize {
	((n + 1) >> 1) * (n + usize::from(n & 1 == 0))
}

fn compute_pascal_triange(n: usize) -> Vec<u64> {
	let mut triangle = vec![0; triangular_number(n + 1)];
	let mut z = 0;
	for i in 0..n {
		for j in 0..=i {
			triangle[z] = if j > 0 && j < i {
				(triangle[z - i - 1] + triangle[z - i]) % MODULO
			} else {
				1
			};
			z += 1;
		}
	}
	triangle
}

fn main() {
	assert_eq!(triangular_number(4), 10);
	assert_eq!(triangular_number(5), 15);
	assert_eq!(1, Solution::num_of_ways(vec![2, 1, 3]));
	assert_eq!(5, Solution::num_of_ways(vec![3, 4, 5, 1, 2]));
	assert_eq!(0, Solution::num_of_ways(vec![1, 2, 3]));
	assert_eq!(
		216212978,
		Solution::num_of_ways(vec![
			9, 4, 2, 1, 3, 6, 5, 7, 8, 14, 11, 10, 12, 13, 16, 15, 17, 18
		])
	);
	assert_eq!(
		182440977,
		Solution::num_of_ways(vec![
			10, 23, 12, 18, 4, 29, 2, 8, 41, 31, 25, 21, 14, 35, 26, 5, 19, 43, 22, 37, 9, 20, 44,
			28, 1, 39, 30, 38, 36, 6, 13, 16, 27, 17, 34, 7, 15, 3, 11, 24, 42, 33, 40, 32
		])
	);
}
