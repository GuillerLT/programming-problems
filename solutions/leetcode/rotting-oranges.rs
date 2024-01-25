/* Problem rotting-oranges
 * https://www.leetcode.com/problems/rotting-oranges
 */

struct Solution;

impl Solution {
	pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
		let mut fresh = std::collections::BTreeSet::new();
		let mut rotten = std::collections::BTreeSet::new();
		for (i, row) in grid.into_iter().enumerate() {
			for (j, cell) in row.into_iter().enumerate() {
				match cell {
					2 => {
						rotten.insert((i + 1, j + 1));
					}
					1 => {
						fresh.insert((i + 1, j + 1));
					}
					0 => {}
					_ => panic!(),
				}
			}
		}
		let mut rotten_new = Vec::new();
		for minute in 0.. {
			if fresh.is_empty() {
				return minute;
			}
			if rotten.is_empty() {
				return -1;
			}
			while let Some((rotten_i, rotten_j)) = rotten.pop_first() {
				if fresh.remove(&(rotten_i - 1, rotten_j)) {
					rotten_new.push((rotten_i - 1, rotten_j));
				}
				if fresh.remove(&(rotten_i + 1, rotten_j)) {
					rotten_new.push((rotten_i + 1, rotten_j));
				}
				if fresh.remove(&(rotten_i, rotten_j - 1)) {
					rotten_new.push((rotten_i, rotten_j - 1));
				}
				if fresh.remove(&(rotten_i, rotten_j + 1)) {
					rotten_new.push((rotten_i, rotten_j + 1));
				}
			}
			rotten.extend(rotten_new.drain(..));
		}
		panic!()
	}
}

pub fn main() {}
