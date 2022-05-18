/* Problem largest-combination-with-bitwise-and-greater-than-zero
 * https://www.leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero
 */

struct Solution;

impl Solution {
    pub fn largest_combination(candidates: Vec<i32>) -> i32 {
        candidates
            .iter()
            .map(|candidate| (0..32).map(move |bit| (candidate >> bit) & 1))
            .fold([0].repeat(31), |acums, bits| {
                acums
                    .iter()
                    .zip(bits)
                    .map(|(acums, bit)| acums + bit)
                    .collect()
            })
            .iter()
            .max()
            .unwrap()
            .to_owned()
    }
}
fn main() {}
