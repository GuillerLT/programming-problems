/* Year 2022 - Day 13
 * https://adventofcode.com/2022/day/13
 */

use std::io::BufRead;

fn main() {
	let packets: Vec<Node> = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.flat_map(|line| {
			let line = line.trim();
			(!line.is_empty()).then(|| line.parse().unwrap())
		})
		.collect();

	println!("{}", part1(&packets));
	println!("{}", part2(&packets));
}

#[derive(Clone, Debug)]
enum Node {
	List(Vec<Node>),
	U8(u8),
}

impl std::str::FromStr for Node {
	type Err = ();

	fn from_str(str: &str) -> Result<Self, Self::Err> {
		if str.is_empty() {
			Ok(Self::List(Vec::default()))
		} else if str.starts_with('[') && str.ends_with(']') {
			Ok(Self::List({
				let str = &str[1..str.len() - 1];
				let mut list = Vec::default();

				let mut last = 0;
				let mut level = 0;
				for (i, c) in str.chars().chain(std::iter::once(',')).enumerate() {
					match c {
						'[' => level += 1,
						']' => level -= 1,
						',' if level == 0 => {
							list.push(str[last..i].parse().unwrap());
							last = i + 1;
						}
						_ => {}
					}
				}

				list
			}))
		} else {
			Ok(Self::U8(str.parse().unwrap()))
		}
	}
}

impl std::cmp::PartialEq for Node {
	fn eq(&self, other: &Self) -> bool {
		self.cmp(other) == std::cmp::Ordering::Equal
	}
}
impl std::cmp::Eq for Node {}

impl std::cmp::PartialOrd for Node {
	fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
		Some(self.cmp(other))
	}
}

impl std::cmp::Ord for Node {
	fn cmp(&self, other: &Self) -> std::cmp::Ordering {
		match (self, other) {
			(Self::U8(s), Self::U8(o)) => s.cmp(o),
			(Self::U8(s), Self::List(_)) => Self::List(Vec::from([Self::U8(*s)])).cmp(other),
			(Self::List(_), Self::U8(o)) => self.cmp(&Self::List(Vec::from([Self::U8(*o)]))),
			(Self::List(s), Self::List(o)) => s.cmp(o),
		}
	}
}

fn part1(packets: &[Node]) -> usize {
	packets
		.chunks(2)
		.enumerate()
		.flat_map(|(i, ab)| (&ab[0] <= &ab[1]).then(|| i + 1))
		.sum()
}

fn part2(packets: &[Node]) -> usize {
	let s2 = Node::List(Vec::from([Node::List(Vec::from([Node::U8(2)]))]));
	let s6 = Node::List(Vec::from([Node::List(Vec::from([Node::U8(6)]))]));
	let mut packets = Vec::from(packets);
	packets.push(s2.clone());
	packets.push(s6.clone());
	packets.sort_unstable();
	(packets.binary_search(&s2).unwrap() + 1) * (packets.binary_search(&s6).unwrap() + 1)
}
