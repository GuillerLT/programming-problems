/* Year 2022 - Day 7
 * https://adventofcode.com/2022/day/7
 */

use std::{collections::BTreeMap, io::BufRead};

fn main() {
	let mut pwd = Vec::default();
	let mut fs = BTreeMap::default();
	for line in std::io::BufReader::new(std::io::stdin()).lines().flatten() {
		let mut tokens = line.split_ascii_whitespace();
		match tokens.next().unwrap() {
			"$" => match tokens.next().unwrap() {
				"cd" => match tokens.next().unwrap() {
					".." => {
						pwd.pop();
					}
					"/" => {
						pwd.clear();
					}
					dir => {
						pwd.push(dir.to_string());
					}
				},
				_ => {}
			},
			"dir" => {}
			size => {
				let size: u64 = size.parse().unwrap();
				*fs.entry(String::from("")).or_insert(0u64) += size;
				for path in pwd.iter().scan(String::default(), |path, entry| {
					*path += entry;
					Some(path.clone())
				}) {
					*fs.entry(path).or_insert(0u64) += size;
				}
			}
		}
	}

	println!("{}", part1(&fs));
	println!("{}", part2(&fs));
}

fn part1(fs: &BTreeMap<String, u64>) -> u64 {
	fs.values().filter(|size| **size <= 100000).sum()
}

fn part2(fs: &BTreeMap<String, u64>) -> u64 {
	let excess = fs.get("").unwrap() - 40000000;
	fs.values()
		.filter(|size| **size >= excess)
		.copied()
		.min()
		.unwrap()
}
