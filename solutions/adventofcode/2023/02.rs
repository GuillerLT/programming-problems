/* Year 2023 - Day 2
 * https://adventofcode.com/2023/day/2
 */

pub fn main() {
	part1();
	part2();
}

fn part1() {
	let input = std::io::BufReader::new(std::fs::File::open("input.txt").unwrap());
	use std::io::BufRead;
	let result: u64 = input
		.lines()
		.map(|line| get_index_if_valid(&line.unwrap()))
		.sum();
	println!("{result}");
}

fn part2() {
	let input = std::io::BufReader::new(std::fs::File::open("input.txt").unwrap());
	use std::io::BufRead;
	let result: u64 = input.lines().map(|line| get_power(&line.unwrap())).sum();
	println!("{result}");
}

fn get_index_if_valid(line: &str) -> u64 {
	let (index, blocks) = line.split_once(':').unwrap();
	if are_blocks_valid(blocks.trim()) {
		index.split_once(' ').unwrap().1.parse().unwrap()
	} else {
		0
	}
}

fn are_blocks_valid(blocks: &str) -> bool {
	blocks.split(';').all(|block| is_block_valid(block.trim()))
}

fn is_block_valid(block: &str) -> bool {
	block.split(',').all(|group| is_group_valid(group.trim()))
}

fn is_group_valid(group: &str) -> bool {
	let (n, color) = group.split_once(' ').unwrap();
	let n: u64 = n.parse().unwrap();
	let limit = match color {
		"red" => 12,
		"green" => 13,
		"blue" => 14,
		_ => panic!(),
	};
	n <= limit
}

fn get_power(line: &str) -> u64 {
	let blocks = line.split_once(':').unwrap().1;
	let (r, g, b) = get_blocks_minimum(blocks.trim());
	r * g * b
}

fn get_blocks_minimum(blocks: &str) -> (u64, u64, u64) {
	blocks
		.split(';')
		.map(|block| get_block_minimum(block.trim()))
		.fold((0, 0, 0), |(rm, gm, bm), (r, g, b)| {
			(rm.max(r), gm.max(g), bm.max(b))
		})
}

fn get_block_minimum(block: &str) -> (u64, u64, u64) {
	block
		.split(',')
		.map(|group| get_group_minimum(group.trim()))
		.fold((0, 0, 0), |(rm, gm, bm), (r, g, b)| {
			(rm.max(r), gm.max(g), bm.max(b))
		})
}

fn get_group_minimum(group: &str) -> (u64, u64, u64) {
	let (n, color) = group.split_once(' ').unwrap();
	let n = n.parse().unwrap();
	match color {
		"red" => (n, 0, 0),
		"green" => (0, n, 0),
		"blue" => (0, 0, n),
		_ => panic!(),
	}
}
