/* Year 2022 - Day 4
 * https://adventofcode.com/2022/day/4
 */

fn main() {
	use std::io::BufRead;
	let sections: Vec<_> = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.flat_map(|line| {
			line.split_once(',').and_then(|(a, b)| {
				let get_limits = |section: &str| {
					section
						.split_once("-")
						.map(|(begin, end)| (begin.parse().unwrap(), end.parse().unwrap()))
				};
				get_limits(a).zip(get_limits(b))
			})
		})
		.map(|((a, b), (x, y))| {
			if a < x || a == x && b > y {
				((a, b), (x, y))
			} else {
				((x, y), (a, b))
			}
		})
		.collect();

	println!("{}", part1(&sections));
	println!("{}", part2(&sections));
}

fn part1(sections: &[((u64, u64), (u64, u64))]) -> usize {
	sections.iter().filter(|((_, b), (_, y))| b >= y).count()
}

fn part2(sections: &[((u64, u64), (u64, u64))]) -> usize {
	sections.iter().filter(|((_, b), (x, _))| b >= x).count()
}
