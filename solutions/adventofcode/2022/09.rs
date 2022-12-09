/* Year 2022 - Day 9
 * https://adventofcode.com/2022/day/9
 */

use std::{collections::BTreeSet, io::BufRead};

fn main() {
	let movements: Vec<_> = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.filter(|line| !line.trim().is_empty())
		.map(|line| (line.as_bytes()[0], line[1..].trim().parse().unwrap()))
		.collect();

	println!("{}", part1(&movements));
	println!("{}", part2(&movements));
}

fn part1(movements: &[(u8, u8)]) -> usize {
	common(movements, 1)
}

fn part2(movements: &[(u8, u8)]) -> usize {
	common(movements, 9)
}

fn common(movements: &[(u8, u8)], n: usize) -> usize {
	let (mut xh, mut yh) = (0, 0);
	let mut xypts = Vec::from_iter(std::iter::repeat((0, 0, BTreeSet::default())).take(n));

	for (direction, reps) in movements {
		for _ in 0..*reps {
			match direction {
				b'R' => xh += 1,
				b'L' => xh -= 1,
				b'U' => yh += 1,
				b'D' => yh -= 1,
				_ => panic!(),
			}

			let mut xh = xh;
			let mut yh = yh;

			for (xt, yt, pt) in xypts.iter_mut() {
				if i16::abs_diff(*xt, xh) > 1 || i16::abs_diff(*yt, yh) > 1 {
					if *xt < xh {
						*xt += 1;
					} else if *xt > xh {
						*xt -= 1;
					}

					if *yt < yh {
						*yt += 1;
					} else if *yt > yh {
						*yt -= 1;
					}
				}

				pt.insert((*xt, *yt));

				xh = *xt;
				yh = *yt;
			}
		}
	}

	xypts.last().unwrap().2.len()
}
