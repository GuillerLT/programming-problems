/* Year 2022 - Day 15
 * https://adventofcode.com/2022/day/15
 */

use std::io::BufRead;

fn main() {
	let sensors_beacons: Vec<_> = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.map(|line| {
			line.split_once(":")
				.map(|(a, b)| {
					(
						a.split_once(",")
							.map(|(x, y)| (x[12..].parse().unwrap(), y[3..].parse().unwrap()))
							.unwrap(),
						b.split_once(",")
							.map(|(x, y)| (x[24..].parse().unwrap(), y[3..].parse().unwrap()))
							.unwrap(),
					)
				})
				.unwrap()
		})
		.collect();

	let beacons: std::collections::BTreeSet<_> = sensors_beacons
		.iter()
		.copied()
		.map(|(.., (bx, by))| (bx, by))
		.collect();

	let sensors: Vec<_> = sensors_beacons
		.into_iter()
		.map(|((x, y), (bx, by))| {
			(
				(x, y),
				i64::saturating_abs(x - bx) + i64::saturating_abs(y - by),
			)
		})
		.collect();

	println!("{}", part1(&sensors, &beacons));
	println!("{}", part2(&sensors, &beacons));
}

fn part1(sensors: &[((i64, i64), i64)], beacons: &std::collections::BTreeSet<(i64, i64)>) -> usize {
	const BY: i64 = 2000000;
	const W: i64 = 20000000;

	(-W..=W)
		.filter(|bx| {
			let bx = *bx;
			sensors.iter().copied().any(|((x, y), d)| {
				d >= i64::saturating_abs(x - bx) + i64::saturating_abs(y - BY)
					&& !beacons.contains(&(bx, BY))
			})
		})
		.count()
}

fn part2(sensors: &[((i64, i64), i64)], _: &std::collections::BTreeSet<(i64, i64)>) -> i64 {
	const L: i64 = 4000000;

	let mut bx = 0;
	while bx <= L {
		let mut by = 0;
		while by <= L {
			let mut md = -1;

			for ((x, y), d) in sensors.iter().copied() {
				let bd = i64::saturating_abs(x - bx) + i64::saturating_abs(y - by);
				md = i64::max(md, i64::saturating_sub(d, bd));
			}

			if md == -1 {
				return bx * L + by;
			}

			by += i64::max(md, 1);
		}

		bx += 1;
	}

	panic!()
}
