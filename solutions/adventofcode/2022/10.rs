/* Year 2022 - Day 10
 * https://adventofcode.com/2022/day/10
 */

use std::io::BufRead;

fn main() {
	let ops: Vec<_> = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.filter_map(|line| {
			line.trim_start()
				.as_bytes()
				.first()
				.and_then(|op| match *op {
					b'a' => line
						.split_ascii_whitespace()
						.next_back()
						.and_then(|v| v.parse().ok()),
					b'n' => Some(0),
					c => panic!("xd: {}", std::str::from_utf8(&[c]).unwrap()),
				})
		})
		.collect();

	println!("{}", part1(&ops));
	println!("{}", part2(&ops).trim_end());
}

fn part1(ops: &[i64]) -> i64 {
	let mut ans = 0;
	let mut cnt = 0;
	let mut reg = 1;
	for op in ops {
		for _ in 0..if *op == 0 { 1 } else { 2 } {
			if (cnt - 19) % 40 == 0 {
				ans += reg * (cnt + 1);
			}
			cnt += 1;
		}
		reg += op;
	}
	ans
}

fn part2(ops: &[i64]) -> String {
	let mut ans = Vec::default();
	let mut cnt = 1;
	let mut reg = 1;
	for op in ops {
		for _ in 0..if *op == 0 { 1 } else { 2 } {
			ans.push(if i64::abs_diff(reg, (cnt - 1) % 40) <= 1 {
				b'#'
			} else {
				b' '
			});
			cnt += 1;
			if (cnt - 1) % 40 == 0 {
				ans.push(b'\n');
			}
		}
		reg += op;
	}
	String::from_utf8(ans).unwrap()
}
