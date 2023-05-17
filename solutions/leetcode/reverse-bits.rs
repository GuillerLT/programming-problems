/* Problem reverse-bits
 * https://www.leetcode.com/problems/reverse-bits
 */

struct Solution;

impl Solution {
	pub fn reverse_bits(x: u32) -> u32 {
		let x = ((0xffff0000 & x) >> 16) | ((0x0000ffff & x) << 16);
		let x = ((0xff00ff00 & x) >> 8) | ((0x00ff00ff & x) << 8);
		let x = ((0xf0f0f0f0 & x) >> 4) | ((0x0f0f0f0f & x) << 4);
		let x = ((0xcccccccc & x) >> 2) | ((0x33333333 & x) << 2);
		let x = ((0xaaaaaaaa & x) >> 1) | ((0x55555555 & x) << 1);
		x
	}
}

fn main() {}
