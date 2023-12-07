/* Year 2023 - Day 7
 * https://adventofcode.com/2023/day/7
 */

pub fn main() {
	let hands = parse_hands("input_small.txt");
	part1(&hands, Some(6_440));
	part2(&hands, Some(5_905));

	let hands = parse_hands("input.txt");
	part1(&hands, Some(248_113_761));
	part2(&hands, Some(246_285_222));
}

fn part1(hands: &[([u8; 5], u64)], expected: Option<u64>) {
	let winnings = get_winnings(hands, false);
	println!("{winnings}");
	if let Some(expected) = expected {
		assert_eq!(winnings, expected);
	}
}

fn part2(hands: &[([u8; 5], u64)], expected: Option<u64>) {
	let winnings = get_winnings(hands, true);
	println!("{winnings}");
	if let Some(expected) = expected {
		assert_eq!(winnings, expected);
	}
}

fn get_winnings(hands: &[([u8; 5], u64)], wildcard: bool) -> u64 {
	let mut hands = Vec::from_iter(hands.iter().map(|&(mut hand, bet)| {
		for card in &mut hand {
			*card *= u8::from(!wildcard || *card != 11);
		}
		let value = get_hand_value(&hand);
		(value, hand, bet)
	}));
	hands.sort_unstable();
	hands
		.into_iter()
		.enumerate()
		.map(|(ranking, (.., bet))| bet * u64::try_from(ranking + 1).unwrap())
		.sum()
}

fn get_hand_value(hand: &[u8; 5]) -> u8 {
	let wildcards = hand.iter().filter(|&&card| card == 0).count();
	let groups = Vec::from_iter((2..=5).map(|target| {
		(2..=14)
			.filter(move |target_card| {
				hand.iter().filter(|&&card| card == *target_card).count() == target
			})
			.count()
	}));
	match (&groups[..], wildcards) {
		// 5
		(&[_, _, _, 1], 0) => 6, // 5
		(&[_, _, 1, _], 1) => 6, // 4 + 1W
		(&[_, 1, _, _], 2) => 6, // 3 + 2W
		(&[1, _, _, _], 3) => 6, // 2 + 3W
		(_, 4..=5) => 6,         // 1 + 4W or 5W
		// 4
		(&[_, _, 1, _], 0) => 5, // 4
		(&[_, 1, _, _], 1) => 5, // 3 + 1W
		(&[1, _, _, _], 2) => 5, // 2 + 2W
		(_, 3) => 5,             // 1 + 3W
		// 3 + 2
		(&[1, 1, _, _], 0) => 4, // 3 + 2
		(&[2, _, _, _], 1) => 4, // 2 + 2 + 1W
		// 3
		(&[_, 1, _, _], 0) => 3, // 3
		(&[1, _, _, _], 1) => 3, // 2 + 1W
		(_, 2) => 3,             // 1 + 2W
		// 2 + 2
		(&[2, 0, 0, 0], 0) => 2, // 2 + 2
		// 2
		(&[1, 0, 0, 0], 0) => 1, // 2
		(_, 1) => 1,             // 1 + 1
		// ...
		_ => 0,
	}
}

fn parse_hands(file: &str) -> Vec<([u8; 5], u64)> {
	let input = std::io::BufReader::new(std::fs::File::open(file).unwrap());
	use std::io::BufRead;
	input
		.lines()
		.map(|line| parse_hand(line.unwrap()))
		.collect()
}

fn parse_hand(string: String) -> ([u8; 5], u64) {
	let mut tokens = string.split_ascii_whitespace();
	(
		parse_cards(tokens.next().unwrap()),
		tokens.next().unwrap().parse().unwrap(),
	)
}

fn parse_cards(str: &str) -> [u8; 5] {
	Vec::from_iter(str.chars().map(|char| {
		char.to_digit(10).map_or_else(
			|| match char {
				'T' => 10,
				'J' => 11,
				'Q' => 12,
				'K' => 13,
				'A' => 14,
				_ => panic!(),
			},
			|digit| u8::try_from(digit).unwrap(),
		)
	}))
	.try_into()
	.unwrap()
}
