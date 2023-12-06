/* Year 2023 - Day 6
 * https://adventofcode.com/2023/day/6
 */

pub fn main() {
	part1();
	part2();
}

fn part1() {
	let solution = parse_races()
		.into_iter()
		.map(|(time, distance)| distance_between_roots(time, distance))
		.product::<u128>();
	println!("{solution}");
	assert!(solution == 288 || solution == 781_200);
}

fn part2() {
	let (time, distance) = parse_race();
	let solution = distance_between_roots(time, distance);
	println!("{solution}");
	assert!(solution == 71503 || solution == 49_240_091);
}

fn distance_between_roots(b_neg: u128, c: u128) -> u128 {
	let discriminant_sqrtx = sqrt_floor(b_neg * b_neg - 4 * c);
	let r1 = (b_neg - discriminant_sqrtx) / 2 + (b_neg - discriminant_sqrtx) % 2;
	let r1 = r1 + u128::from(r1 * r1 + c >= r1 * b_neg);
	let r2 = (b_neg + discriminant_sqrtx) / 2;
	let r2 = r2 - u128::from(r2 * r2 + c >= r2 * b_neg);
	r2 - r1 + 1
}

fn distance_between_roots_float(b_neg: u128, c: u128) -> u128 {
	let b_neg = b_neg as f64;
	let c = c as f64;
	let discriminant_sqrt = (b_neg * b_neg - 4.0 * c).sqrt();
	let r1 = (b_neg - discriminant_sqrt) / 2.0;
	let r2 = (b_neg + discriminant_sqrt) / 2.0;
	let r1 = r1.floor() as u128;
	let r2 = r2.ceil() as u128;
	r2 - r1 - 1
}

fn sqrt_floor(n: u128) -> u128 {
	(1..)
		.map_while(|m| (m * m <= n).then_some(m))
		.last()
		.unwrap()
}

fn parse_races() -> Vec<(u128, u128)> {
	let input = std::io::BufReader::new(std::fs::File::open("input.txt").unwrap());
	use std::io::BufRead;
	let mut lists = input.lines().map(|line| {
		Vec::from_iter(
			line.unwrap()
				.split_ascii_whitespace()
				.skip(1)
				.map(|token| token.parse().unwrap()),
		)
	});
	lists
		.next()
		.unwrap()
		.into_iter()
		.zip(lists.next().unwrap())
		.collect()
}

fn parse_race() -> (u128, u128) {
	let input = std::io::BufReader::new(std::fs::File::open("input.txt").unwrap());
	use std::io::BufRead;
	let mut lists = input.lines().map(|line| {
		line.unwrap()
			.chars()
			.flat_map(|char| char.to_digit(10))
			.fold(0u128, |n, d| n * 10 + u128::from(d))
	});
	(lists.next().unwrap(), lists.next().unwrap())
}
