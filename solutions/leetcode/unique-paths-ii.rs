/* Problem unique-paths-ii
 * https://www.leetcode.com/problems/unique-paths-ii
 */

impl Solution {
	pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
		let mut r = vec![0; obstacle_grid[0].len()];
		r[0] = 1;
		for row in obstacle_grid.into_iter() {
			for (j, cell) in row.into_iter().enumerate() {
				r[j] = if cell > 0 {
					0
				} else {
					r[j] + if j == 0 { 0 } else { r[j - 1] }
				};
			}
		}
		r.last().copied().unwrap()
	}
}

struct Solution;
