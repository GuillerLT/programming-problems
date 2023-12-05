/* Year 2023 - Day 5
 * https://adventofcode.com/2023/day/5
 */

pub fn main() {
	let (seeds, range_trees) = parse_input();
	part1(&seeds, &range_trees);
	part2(&seeds, &range_trees);
}

type RangeTree = std::collections::BTreeMap<
	u64, /* source range begin */
	(
		u64, /* source range end */
		u64, /* destination map */
	),
>;

fn part1(seeds: &[u64], range_trees: &[RangeTree]) {
	let location = seeds
		.iter()
		.flat_map(|seed| find_range_in_range_trees((*seed, 1), range_trees))
		.map(|(location, _)| location)
		.min()
		.unwrap();
	println!("{location}");
	assert!(location == 35 || location == 51752125);
}

fn part2(seeds: &[u64], range_trees: &[RangeTree]) {
	let location = seeds
		.chunks(2)
		.flat_map(|seed| {
			find_range_in_range_trees((*seed.first().unwrap(), *seed.last().unwrap()), range_trees)
		})
		.map(|(location, _)| location)
		.min()
		.unwrap();
	println!("{location}");
	assert!(location == 46 || location == 12634632);
}

fn find_range_in_range_trees(seed: (u64, u64), range_trees: &[RangeTree]) -> Vec<(u64, u64)> {
	range_trees
		.iter()
		.fold(vec![seed], |cur_ranges, range_tree| {
			cur_ranges
				.into_iter()
				.flat_map(|cur_range| find_range_in_range_tree(cur_range, range_tree))
				.collect()
		})
}

fn find_range_in_range_tree(
	(cur_begin, cur_len): (u64, u64),
	range_tree: &RangeTree,
) -> Vec<(u64, u64)> {
	range_tree
		.range(..=cur_begin)
		.rev()
		.take(1)
		.chain(range_tree.range((cur_begin + 1)..(cur_begin + cur_len)))
		.flat_map(|(source_begin, (source_end, dst))| {
			let next_begin = cur_begin.max(*source_begin);
			let delta = next_begin - source_begin;
			let next_end = (cur_begin + cur_len).min(*source_end);
			let next_len = next_end - next_begin;
			(next_len > 0).then_some((*dst + delta, next_len))
		})
		.collect()
}

fn parse_input() -> (Vec<u64>, Vec<RangeTree>) {
	let input = std::io::BufReader::new(std::fs::File::open("input.txt").unwrap());
	use std::io::BufRead;
	let mut lines = input.lines();
	let seeds = parse_seeds(&lines.next().unwrap().unwrap());
	let maps = lines.fold(vec![vec![]], |mut maps, line| {
		let last = maps.last_mut().unwrap();
		match parse_map(&line.unwrap()) {
			Some(map) => last.push(map),
			None => {
				if !last.is_empty() {
					maps.push(vec![]);
				}
			}
		};
		maps
	});
	(seeds, to_range_trees(maps))
}

fn parse_seeds(str: &str) -> Vec<u64> {
	str.split_ascii_whitespace()
		.flat_map(|token| token.parse())
		.collect()
}

fn parse_map(str: &str) -> Option<(u64, u64, u64)> {
	let mut tokens = str.split_ascii_whitespace();
	match (tokens.next(), tokens.next(), tokens.next()) {
		(Some(destination), Some(source), Some(len)) => {
			match (destination.parse(), source.parse(), len.parse()) {
				(Ok(destination), Ok(source), Ok(len)) => Some((destination, source, len)),
				_ => None,
			}
		}
		_ => None,
	}
}

fn to_range_trees(maps: Vec<Vec<(u64, u64, u64)>>) -> Vec<RangeTree> {
	maps.into_iter().map(to_range_tree).collect()
}

fn to_range_tree(map: Vec<(u64, u64, u64)>) -> RangeTree {
	let mut range_tree = RangeTree::new();
	range_tree.insert(0, (u64::MAX, 0));
	for (destination, source, len) in map {
		range_tree.insert(source, (source + len, destination));
		range_tree
			.entry(source + len)
			.or_insert((u64::MAX, source + len));
	}
	range_tree
}
