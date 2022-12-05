/* Year 2022 - Day 2
 * https://adventofcode.com/2022/day/2
 */

const P1: u8 = b'A' - 1;
const P2: u8 = b'X' - 1;

// Rock			: A X 1
// Paper		: B Y 2
// Scissors	: C Z 3
// Lose			:   X 1
// Draw			:   Y 2
// Win			:   Z 3
fn main() {
	use std::io::BufRead;
	let strategy: Vec<_> = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.flat_map(|line| {
			let mut bytes = line.bytes();
			bytes
				.next()
				.map(|byte| byte - P1)
				.zip(bytes.rev().next().map(|byte| byte - P2))
		})
		.collect();

	println!("{}", part1(&strategy));
	println!("{}", part2(&strategy));
}

fn part1(strategy: &[(u8, u8)]) -> u64 {
	strategy
		.iter()
		.map(|(a, b)| {
			b + match (a, b) {
				(1, 1) => 3u8,
				(1, 2) => 6u8,
				(1, 3) => 0u8,
				(2, 1) => 0u8,
				(2, 2) => 3u8,
				(2, 3) => 6u8,
				(3, 1) => 6u8,
				(3, 2) => 0u8,
				(3, 3) => 3u8,
				_ => panic!(),
			}
		})
		.map(u64::from)
		.sum()
}

fn part2(strategy: &[(u8, u8)]) -> u64 {
	strategy
		.iter()
		.map(|(a, b)| match (a, b) {
			(1, 1) => 3u8 + 0,
			(1, 2) => 1u8 + 3,
			(1, 3) => 2u8 + 6,
			(2, 1) => 1u8 + 0,
			(2, 2) => 2u8 + 3,
			(2, 3) => 3u8 + 6,
			(3, 1) => 2u8 + 0,
			(3, 2) => 3u8 + 3,
			(3, 3) => 1u8 + 6,
			_ => panic!(),
		})
		.map(u64::from)
		.sum()
}
