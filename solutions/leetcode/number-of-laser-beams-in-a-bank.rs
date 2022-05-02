/* Problem number-of-laser-beams-in-a-bank
 * https://www.leetcode.com/problems/number-of-laser-beams-in-a-bank
 */

struct Solution;

impl Solution {
    pub fn number_of_beams(bank: Vec<String>) -> i32 {
        let devices = bank
            .iter()
            .map(|row| row.chars().filter(|col| *col == '1').count())
            .filter(|row| *row > 0)
            .collect::<Vec<usize>>();
        devices
            .windows(2)
            .map(|rows| rows[0] * rows[1])
            .sum::<usize>() as i32
    }
}

pub fn main() {}
