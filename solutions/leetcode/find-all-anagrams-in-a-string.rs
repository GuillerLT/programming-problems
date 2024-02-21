/* Problem find-all-anagrams-in-a-string
 * https://www.leetcode.com/problems/find-all-anagrams-in-a-string
 */

struct Solution;

fn freq(bytes: &[u8]) -> [usize; 26] {
	let mut f = [0; 26];
	for byte in bytes {
		f[(*byte - u8::try_from('a').unwrap()) as usize] += 1;
	}
	f
}

impl Solution {
	pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
		let s = s.as_bytes();
		let p = p.as_bytes();

		if s.len() < p.len() {
			return vec![];
		}

		let target = freq(p);
		let mut current = freq(&s[..p.len()]);
		let mut anagram_starts = vec![];
		if current == target {
			anagram_starts.push(0)
		};
		for i in p.len()..s.len() {
			current[(s[i - p.len()] - u8::try_from('a').unwrap()) as usize] -= 1;
			current[(s[i] - u8::try_from('a').unwrap()) as usize] += 1;
			if current == target {
				anagram_starts.push((i - p.len() + 1) as i32)
			};
		}

		anagram_starts
	}
}

fn main() {
	Solution::find_anagrams("zzz".to_string(), "zzz".to_string());
}
