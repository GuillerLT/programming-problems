/* Year 2023 - Day 1
 * https://adventofcode.com/2023/day/1
 */

pub fn main() {
	part1();
	part2();
}

fn part1() {
	let input = std::io::BufReader::new(std::fs::File::open("input.txt").unwrap());
	use std::io::BufRead;
	let sum: u64 = input.lines().flatten().map(find_digits).sum();
	println!("{sum}");
}

fn part2() {
	let input = std::io::BufReader::new(std::fs::File::open("input.txt").unwrap());
	use std::io::BufRead;
	let sum: usize = input.lines().flatten().map(find_digits_or_spellings).sum();
	println!("{sum}");
}

fn find_digits(string: String) -> u64 {
	let f = find_digit(string.chars());
	let l = find_digit(string.chars().rev());
	(10 * f + l).into()
}

fn find_digit(chars: impl Iterator<Item = char>) -> u32 {
	chars.filter_map(|c| c.to_digit(10)).next().unwrap()
}

fn find_digits_or_spellings(string: String) -> usize {
	let f = find_digit_or_spelling(&string, false);
	let l = find_digit_or_spelling(&string, true);
	10 * f + l
}

fn find_digit_or_spelling(str: &str, reverse: bool) -> usize {
	const TOKENS: &[&str] = &[
		"1", "2", "3", "4", "5", "6", "7", "8", "9", "one", "two", "three", "four", "five", "six",
		"seven", "eight", "nine",
	];

	let mut tokenizer = (0..str.len()).filter_map(|i| {
		TOKENS
			.iter()
			.enumerate()
			.filter_map(|(j, token)| str[i..].starts_with(token).then_some(j % 9 + 1))
			.next()
	});

	if !reverse {
		tokenizer.next()
	} else {
		tokenizer.next_back()
	}
	.unwrap()
}
