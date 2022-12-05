/* Year 2022 - Day 1
 * https://adventofcode.com/2022/day/1
 */

fn main() {
	use std::io::BufRead;
	let input = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.map(|line| line.parse().unwrap_or(0u64));

	let mut calories = process_input(input);

	println!("{}", part1(&calories));
	println!("{}", part2(&mut calories));
}

fn process_input(input: impl Iterator<Item = u64>) -> Vec<u64> {
	input
		.scan(0, |accum, calory| {
			Some(if calory == 0 {
				std::mem::replace(accum, 0)
			} else {
				*accum += calory;
				0
			})
		})
		.filter(|calory| *calory > 0)
		.collect()
}

fn part1(calories: &[u64]) -> u64 {
	calories.iter().copied().max().unwrap_or_default()
}

fn part2(calories: &mut [u64]) -> u64 {
	calories
		.select_nth_unstable(calories.len() - 4)
		.2
		.iter()
		.sum()
}
