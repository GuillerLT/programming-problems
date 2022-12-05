/* Year 2022 - Day 3
 * https://adventofcode.com/2022/day/3
 */

fn main() {
	use std::io::BufRead;
	let rucksacks: Vec<_> = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.filter(|line| !line.trim().is_empty())
		.collect();

	println!("{}", part1(&rucksacks));
	println!("{}", part2(&rucksacks));
}

fn part1(rucksacks: &[String]) -> u64 {
	rucksacks
		.iter()
		.map(|rucksack| -> u64 {
			let rucksack = rucksack.trim().as_bytes();
			let mut compartiments = rucksack
				.chunks(rucksack.len() / 2)
				.map(|compartiment| std::collections::BTreeSet::from_iter(compartiment));
			let a = compartiments.next().unwrap();
			let b = compartiments.next().unwrap();
			a.intersection(&b)
				.map(|item| match item {
					b'a'..=b'z' => *item - (b'a' - 1),
					b'A'..=b'Z' => *item - (b'A' - 27),
					_ => panic!(),
				})
				.map(u64::from)
				.sum()
		})
		.sum()
}

fn part2(rucksacks: &[String]) -> u64 {
	rucksacks
		.chunks(3)
		.map(|group| -> u64 {
			let mut group = group.iter().map(|rucksack| {
				let rucksack = rucksack.trim().as_bytes();
				std::collections::BTreeSet::from_iter(rucksack)
			});
			let a = group.next().unwrap();
			let b = group.next().unwrap();
			let c = group.next().unwrap();
			std::collections::BTreeSet::from_iter(a.intersection(&b).copied())
				.intersection(&c)
				.map(|item| match item {
					b'a'..=b'z' => *item - (b'a' - 1),
					b'A'..=b'Z' => *item - (b'A' - 27),
					_ => panic!(),
				})
				.map(u64::from)
				.sum()
		})
		.sum()
}
