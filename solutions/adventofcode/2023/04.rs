/* Year 2023 - Day 4
 * https://adventofcode.com/2023/day/4
 */

use std::collections::BTreeSet;

pub fn main() {
	let cards = parse_cards();
	part1(&cards);
	part2(&cards);
}

fn part1(cards: &[(BTreeSet<u64>, BTreeSet<u64>)]) {
	let score: u64 = cards.iter().map(score_card).sum();
	println!("{score}")
}

fn part2(cards: &[(BTreeSet<u64>, BTreeSet<u64>)]) {
	let count: u64 = cards
		.iter()
		.enumerate()
		.fold(
			vec![1; cards.len()],
			|mut counts, (i, (winning, played))| {
				for j in 1..=winning.intersection(played).count() {
					counts[j + i] += counts[i];
				}
				counts
			},
		)
		.into_iter()
		.sum();
	println!("{count}")
}

fn score_card((winning, played): &(BTreeSet<u64>, BTreeSet<u64>)) -> u64 {
	match winning.intersection(played).count() {
		0 => 0,
		n => 1 << (n - 1),
	}
}

fn parse_cards() -> Vec<(BTreeSet<u64>, BTreeSet<u64>)> {
	let input = std::io::BufReader::new(std::fs::File::open("input.txt").unwrap());
	use std::io::BufRead;
	input
		.lines()
		.map(|card| parse_card(&card.unwrap()))
		.collect()
}

fn parse_card(card: &str) -> (BTreeSet<u64>, BTreeSet<u64>) {
	let card = card.split_once(':').unwrap().1;
	let (winning, played) = card.split_once('|').unwrap();
	(parse_numbers(winning), parse_numbers(played))
}

fn parse_numbers(numbers: &str) -> BTreeSet<u64> {
	numbers
		.split_whitespace()
		.map(|number| number.parse().unwrap())
		.collect()
}
