/* Year 2022 - Day 8
 * https://adventofcode.com/2022/day/8
 */

use std::{collections::BTreeSet, io::BufRead};

fn main() {
	let (forest, w, h): (Vec<_>, usize, usize) = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.fold(
			(Vec::default(), 0, 0),
			|(mut forest, mut w, mut h), line| {
				let line = line.trim().as_bytes();
				if !line.is_empty() {
					forest.extend(line.iter().copied());
					w = line.len();
					h += 1;
				}
				(forest, w, h)
			},
		);

	println!("{}", part1(&forest, w, h));
	println!("{}", part2(&forest, w, h));
}

fn part1(forest: &[u8], w: usize, h: usize) -> usize {
	let mut trees = BTreeSet::default();
	trees.append(&mut visibility_outside(forest, w, h, false, false));
	trees.append(&mut visibility_outside(forest, w, h, false, true));
	trees.append(&mut visibility_outside(forest, w, h, true, false));
	trees.append(&mut visibility_outside(forest, w, h, true, true));
	trees.len()
}

fn visibility_outside(
	forest: &[u8],
	w: usize,
	h: usize,
	direction: bool,
	orientation: bool,
) -> BTreeSet<(usize, usize)> {
	let mut trees = BTreeSet::default();
	let mut visibility =
		Vec::from_iter(std::iter::repeat(u8::MIN).take(if direction { w } else { h }));

	for a in 0..if direction { h } else { w } {
		let a = if orientation {
			a
		} else {
			(if direction { h } else { w }) - 1 - a
		};
		for b in 0..if direction { w } else { h } {
			let b = if orientation {
				b
			} else {
				(if direction { w } else { h }) - 1 - b
			};
			let (x, y) = if direction { (b, a) } else { (a, b) };
			if forest[x + y * w] > visibility[b] {
				trees.insert((x, y));
				visibility[b] = forest[x + y * w];
			}
		}
	}
	trees
}

fn part2(forest: &[u8], w: usize, h: usize) -> usize {
	(0..w)
		.flat_map(|x| {
			(0..h).map(move |y| {
				visibility_inside(forest, w, h, false, false, x, y)
					* visibility_inside(forest, w, h, false, true, x, y)
					* visibility_inside(forest, w, h, true, false, x, y)
					* visibility_inside(forest, w, h, true, true, x, y)
			})
		})
		.max()
		.unwrap()
}

fn visibility_inside(
	forest: &[u8],
	w: usize,
	h: usize,
	direction: bool,
	orientation: bool,
	mut x: usize,
	mut y: usize,
) -> usize {
	let t = forest[x + y * w];

	let mut count = 0;
	loop {
		if x == 0 && direction == false && orientation == false
			|| x == w - 1 && direction == false && orientation == true
			|| y == 0 && direction == true && orientation == false
			|| y == h - 1 && direction == true && orientation == true
		{
			break;
		}

		x = if direction == false {
			if orientation == true {
				x + 1
			} else {
				x - 1
			}
		} else {
			x
		};
		y = if direction == true {
			if orientation == true {
				y + 1
			} else {
				y - 1
			}
		} else {
			y
		};

		count += 1;
		if forest[x + y * w] >= t {
			break;
		}
	}
	count
}
