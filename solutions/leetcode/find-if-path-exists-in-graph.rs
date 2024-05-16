/* Problem find-if-path-exists-in-graph
 * https://www.leetcode.com/problems/find-if-path-exists-in-graph
 */

struct Solution;

impl Solution {
	pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
		let mut edges = edges
			.into_iter()
			.map(|edge| (edge[0] as usize, edge[1] as usize))
			.flat_map(|(source, destination)| [(source, destination), (destination, source)])
			.collect::<Vec<_>>();
		edges.sort_unstable();
		edges.dedup();
		let edges = edges;
		let (source, target) = (source as usize, destination as usize);
		if source == target {
			return true;
		}
		let mut visited = vec![false; n as usize + 1];
		let mut pendings = std::collections::BTreeSet::new();
		pendings.insert(source);
		while let Some(pending) = pendings.pop_last() {
			let Ok(index) = edges.binary_search_by_key(&pending, |(source, _)| *source) else {
				continue;
			};
			for i in (0..index).rev() {
				let (source, destination) = edges[i];
				if source != pending {
					break;
				}
				if destination == target {
					return true;
				}
				if visited[destination] == true {
					continue;
				}
				pendings.insert(destination);
				visited[destination] = true;
			}
			for i in index..edges.len() {
				let (source, destination) = edges[i];
				if source != pending {
					break;
				}
				if destination == target {
					return true;
				}
				if visited[destination] == true {
					continue;
				}
				pendings.insert(destination);
				visited[destination] = true;
			}
		}
		false
	}
}

fn main() {}
