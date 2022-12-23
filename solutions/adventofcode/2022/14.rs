/* Year 2022 - Day 14
 * https://adventofcode.com/2022/day/14
 */

use std::io::BufRead;

const W: usize = 560;
const H: usize = 170;

fn main() {
	let mut cave = [false; W * H];
	for line in std::io::BufReader::new(std::io::stdin()).lines().flatten() {
		let coords: Vec<(usize, usize)> = line
			.split(" -> ")
			.map(|coord| {
				coord
					.split_once(',')
					.map(|(x, y)| (x.parse().unwrap(), y.parse().unwrap()))
					.unwrap()
			})
			.collect();

		for coords in coords.windows(2) {
			let a = coords.iter().min().unwrap();
			let b = coords.iter().max().unwrap();
			for x in a.0..=b.0 {
				assert!(x < W);
				cave[a.1 * W + x] = true;
			}
			for y in a.1..=b.1 {
				assert!(y < H);
				cave[y * W + a.0] = true;
			}
		}
	}

	println!("{}", part1(&cave));
	println!("{}", part2(&cave));
}

fn part1(cave: &[bool; W * H]) -> usize {
	let mut cave = cave.clone();
	let mut sand = 0;
	loop {
		let (mut x, mut y) = (500, 0);
		while y < H - 1 {
			if !cave[(y + 1) * W + x] {
				y += 1;
			} else if !cave[(y + 1) * W + x - 1] {
				y += 1;
				x -= 1;
			} else if !cave[(y + 1) * W + x + 1] {
				y += 1;
				x += 1;
			} else {
				break;
			}
		}

		if y + 1 == H {
			break sand;
		}

		cave[y * W + x] = true;
		sand += 1;
	}
}

fn part2(cave: &[bool; W * H]) -> usize {
	let h = (0..H)
		.rev()
		.find(|y| (0..W).any(|x| cave[y * W + x]))
		.unwrap()
		+ 1;

	let mut cave = cave.clone();
	let mut sand = 0;
	loop {
		let (mut x, mut y) = (500, 0);
		while y < h {
			if !cave[(y + 1) * W + x] {
				y += 1;
			} else if !cave[(y + 1) * W + x - 1] {
				y += 1;
				x -= 1;
			} else if !cave[(y + 1) * W + x + 1] {
				y += 1;
				x += 1;
			} else {
				break;
			}
		}

		if (x, y) == (500, 0) {
			break sand + 1;
		}

		cave[y * W + x] = true;
		sand += 1;
	}
}
