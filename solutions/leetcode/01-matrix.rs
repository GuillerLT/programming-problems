/* Problem 01-matrix
 * https://www.leetcode.com/problems/01-matrix
 */

struct Solution;

impl Solution {
	pub fn update_matrix(mut mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
		let h = mat.len();
		let w = mat.first().unwrap().len();

		for r in 0..h {
			for c in 0..w {
				if mat[r][c] != 0 {
					let top = mat
						.get(r - 1)
						.and_then(|row| row.get(c))
						.cloned()
						.unwrap_or(i32::MAX);
					let left = mat
						.get(r)
						.and_then(|row| row.get(c - 1))
						.cloned()
						.unwrap_or(i32::MAX);

					mat[r][c] = i32::min(top, left).saturating_add(1);
				}
			}
		}

		for r in (0..h).rev() {
			for c in (0..w).rev() {
				if mat[r][c] != 0 {
					let bottom = mat
						.get(r + 1)
						.and_then(|row| row.get(c))
						.cloned()
						.unwrap_or(i32::MAX);
					let right = mat
						.get(r)
						.and_then(|row| row.get(c + 1))
						.cloned()
						.unwrap_or(i32::MAX);

					mat[r][c] = i32::min(mat[r][c], i32::min(bottom, right).saturating_add(1));
				}
			}
		}

		mat
	}
}

pub fn main() {}
