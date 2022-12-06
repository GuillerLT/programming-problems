/* Year 2022 - Day 6
 * https://adventofcode.com/2022/day/6
 */

fn main() {
	use std::io::BufRead;
	let input = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.next()
		.unwrap();

	println!("{}", part1(input.as_bytes()));
	println!("{}", part2(input.as_bytes()));
}

fn part1(data: &[u8]) -> usize {
	common(data, 4)
}

fn part2(data: &[u8]) -> usize {
	common(data, 14)
}

fn common(data: &[u8], n: usize) -> usize {
	data.windows(n)
		.position(|window| (1..window.len()).all(|i| !window[i..].contains(&window[i - 1])))
		.unwrap()
		+ n
}
