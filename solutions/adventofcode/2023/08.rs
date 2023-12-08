/* Year 2023 - Day 8
 * https://adventofcode.com/2023/day/8
 */

pub fn main() {
	let (directions, map) = parse_input("input_small.txt");
	part2(&directions, &map, Some(6));

	let (directions, map) = parse_input("input.txt");
	part1(&directions, &map, Some(17263));
	part2(&directions, &map, Some(14631604759649));
}

fn part1(
	directions: &[bool],
	map: &std::collections::BTreeMap<[char; 3], ([char; 3], [char; 3])>,
	expected: Option<usize>,
) {
	let solution = get_next_step(directions, map, ['A', 'A', 'A'], false);
	println!("{solution}");
	if let Some(expected) = expected {
		assert_eq!(solution, expected);
	}
}

fn part2(
	directions: &[bool],
	map: &std::collections::BTreeMap<[char; 3], ([char; 3], [char; 3])>,
	expected: Option<usize>,
) {
	let solution = map
		.keys()
		.filter(|&&[.., char]| matches!(char, 'A'))
		.map(|&start| get_next_step(directions, map, start, true))
		.fold(1, lcm);
	println!("{solution}");
	if let Some(expected) = expected {
		assert_eq!(solution, expected);
	}
}

fn get_next_step(
	directions: &[bool],
	map: &std::collections::BTreeMap<[char; 3], ([char; 3], [char; 3])>,
	start: [char; 3],
	check_last_only: bool,
) -> usize {
	directions
		.iter()
		.cycle()
		.enumerate()
		.scan(start, |current, (step, &direction)| {
			let nexts = map.get(current).unwrap();
			let next = if direction { nexts.0 } else { nexts.1 };
			(!matches!(
				(std::mem::replace(current, next), check_last_only),
				([.., 'Z'], true) | (['Z', 'Z', 'Z'], _)
			))
			.then_some(step)
		})
		.last()
		.unwrap()
		+ 1
}

fn gcd(a: usize, b: usize) -> usize {
	if b == 0 {
		a
	} else {
		gcd(b, a % b)
	}
}

fn lcm(a: usize, b: usize) -> usize {
	a * b / gcd(a, b)
}

fn parse_input(
	file: &str,
) -> (
	Vec<bool>,
	std::collections::BTreeMap<[char; 3], ([char; 3], [char; 3])>,
) {
	let input = std::io::BufReader::new(std::fs::File::open(file).unwrap());
	use std::io::BufRead;
	let mut lines = input.lines();
	let directions = lines
		.next()
		.unwrap()
		.unwrap()
		.chars()
		.map(|char| match char {
			'L' => true,
			'R' => false,
			_ => panic!(),
		})
		.collect();
	let map = lines
		.map(|line| line.unwrap())
		.filter(|line| !line.is_empty())
		.map(|line| {
			let mut chars = line.chars().filter(|char| char.is_ascii_alphanumeric());
			(
				[
					chars.next().unwrap(),
					chars.next().unwrap(),
					chars.next().unwrap(),
				],
				(
					[
						chars.next().unwrap(),
						chars.next().unwrap(),
						chars.next().unwrap(),
					],
					[
						chars.next().unwrap(),
						chars.next().unwrap(),
						chars.next().unwrap(),
					],
				),
			)
		})
		.collect();
	(directions, map)
}
