/* Problem maximum-length-of-a-concatenated-string-with-unique-characters
 * https://www.leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
 */

struct Solution;

impl Solution {
  pub fn max_length(arr: Vec<String>) -> i32 {
    fn to_len_and_set(s: &String) -> (u32, i32) {
      let mut set : u32 = 0;
      for c in s.chars() {
        let i = 1 << (c as u32 - 'a' as u32);
        if set & i != 0 { return (0, 0); }
        set |= i;
      }
      (set, s.len() as i32)
    }
    let arr = arr.iter()
                 .map(to_len_and_set)
                 .collect::<Vec<(u32, i32)>>();
    fn max_len_disjoint_sets(arr: &Vec<(u32, i32)>, i: usize, aset: u32, alen: i32) -> i32 {
      if i >= arr.len() {
        alen
      } else {
        let (set, len) = arr[i];
        let a = max_len_disjoint_sets(arr, i + 1, aset, alen);
        if set & aset == 0 {
          let b = max_len_disjoint_sets(arr, i + 1, aset | set, alen + len);
          std::cmp::max(a, b)
        } else {
          a
        }
      }
    }
    max_len_disjoint_sets(&arr, 0, 0, 0)
  }
}
