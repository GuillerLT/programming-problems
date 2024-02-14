/* Problem time-based-key-value-store
 * https://www.leetcode.com/problems/time-based-key-value-store
 */

struct TimeMap(std::collections::HashMap<String, Vec<(i32, String)>>);

impl TimeMap {
	fn new() -> Self {
		Self(std::collections::HashMap::with_capacity(1024))
	}

	fn set(&mut self, key: String, value: String, timestamp: i32) {
		self.0
			.entry(key)
			.or_insert_with(|| Vec::with_capacity(256))
			.push((timestamp, value))
	}

	fn get(&self, key: String, timestamp: i32) -> String {
		self.0
			.get(&key)
			.and_then(|set| {
				let i = match set.binary_search_by_key(&timestamp, |(t, _)| *t) {
					Ok(ok) => ok,
					Err(err) => err.checked_sub(1)?,
				};
				set.get(i).map(|(_, v)| v.clone())
			})
			.unwrap_or_default()
	}
}

pub fn main() {}
