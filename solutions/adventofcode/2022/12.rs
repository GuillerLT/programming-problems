/* Year 2022 - Day 12
 * https://adventofcode.com/2022/day/12
 */

use std::io::BufRead;

fn main() {
	let (mut map, w, h) = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.fold((Vec::default(), 0, 0), |(mut map, mut w, mut h), line| {
			let line = line.trim().as_bytes();
			map.extend(line);
			assert!(w == 0 || w == line.len());
			w = line.len();
			h += 1;
			(map, w, h)
		});

	let (ox, oy) = {
		let i = map
			.iter()
			.enumerate()
			.find_map(|(i, v)| (*v == b'S').then_some(i))
			.unwrap();
		map[i] = b'a';
		(i % w, i / w)
	};

	let (dx, dy) = {
		let i = map
			.iter()
			.enumerate()
			.find_map(|(i, v)| (*v == b'E').then_some(i))
			.unwrap();
		map[i] = b'z';
		(i % w, i / w)
	};

	let map = map;

	println!("{}", part1(&map, w, h, (ox, oy), (dx, dy)));
	println!("{}", part2(&map, w, h, (ox, oy), (dx, dy)));
}

fn part1(map: &[u8], w: usize, h: usize, o: (usize, usize), d: (usize, usize)) -> usize {
	common(map, w, h, std::iter::once(o), d)
}

fn part2(map: &[u8], w: usize, h: usize, _: (usize, usize), d: (usize, usize)) -> usize {
	common(
		map,
		w,
		h,
		map.iter()
			.enumerate()
			.filter_map(|(i, v)| (*v == b'a').then(|| (i % w, i / w))),
		d,
	)
}

fn common(
	map: &[u8],
	w: usize,
	h: usize,
	os: impl Iterator<Item = (usize, usize)>,
	d: (usize, usize),
) -> usize {
	let (dx, dy) = d;

	let mut steps = 0;
	let mut visited = std::collections::BTreeSet::default();
	let mut next = Vec::from_iter(os);

	'a: loop {
		let current = Vec::from_iter(next.drain(..));
		for (x, y) in current {
			if (x, y) == (dx, dy) {
				break 'a steps;
			}

			// up
			if y + 1 < h && map[(y + 1) * w + x] <= map[y * w + x] + 1 && visited.insert((x, y + 1))
			{
				next.push((x, y + 1));
			}

			// down
			if y > 0 && map[(y - 1) * w + x] <= map[y * w + x] + 1 && visited.insert((x, y - 1)) {
				next.push((x, y - 1));
			}

			// right
			if x + 1 < w && map[y * w + x + 1] <= map[y * w + x] + 1 && visited.insert((x + 1, y)) {
				next.push((x + 1, y));
			}

			// left
			if x > 0 && map[y * w + x - 1] <= map[y * w + x] + 1 && visited.insert((x - 1, y)) {
				next.push((x - 1, y));
			}
		}
		steps += 1;
	}
}
