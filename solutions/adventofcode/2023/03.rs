/* Year 2023 - Day 3
 * https://adventofcode.com/2023/day/3
 */

pub fn main() {
	let input = std::io::BufReader::new(std::fs::File::open("input.txt").unwrap());
	use std::io::BufRead;
	let matrix = parse_matrix(input.lines());
	let h = matrix.len();
	let w = matrix.iter().map(Vec::len).max().unwrap();

	part1(&matrix, h, w);
	part2(&matrix, h, w);
}

#[derive(Clone)]
enum Item {
	Number { n: u64, l: u32 },
	Symbol,
	Point,
}

fn part1(matrix: &[Vec<Item>], h: usize, w: usize) {
	let mut sum = 0;
	for i in 0..h {
		let mut j = 0;
		while j < w {
			let Some(Item::Number { n, l }) = matrix.get(i).and_then(|row: &Vec<Item>| row.get(j))
			else {
				j += 1;
				continue;
			};

			let l = (*l).try_into().unwrap();

			let mut symbol_found = false;
			for ii in i.saturating_sub(1)..=i.saturating_add(1) {
				for jj in j.saturating_sub(1)..=j.saturating_add(l) {
					symbol_found |= matches!(
						matrix.get(ii).and_then(|row| row.get(jj)),
						Some(Item::Symbol)
					);
				}
			}
			if symbol_found {
				sum += n;
			}
			j += l;
		}
	}
	println!("{sum}");
}

fn part2(matrix: &[Vec<Item>], h: usize, w: usize) {
	let mut sum = 0;
	for i in 0..h {
		for j in 0..w {
			if !matches!(matrix[i][j], Item::Symbol) {
				continue;
			};
			let mut nums = Vec::new();
			for ii in i.saturating_sub(1)..=i.saturating_add(1) {
				let mut jj = j.saturating_sub(1);
				while jj <= j.saturating_add(1) {
					if let Some(Item::Number { n, l }) =
						matrix.get(ii).and_then(|row: &Vec<Item>| row.get(jj))
					{
						nums.push(*n);
						for jjj in (0..jj).rev() {
							if let Some(Item::Number { n, l: _ }) =
								matrix.get(ii).and_then(|row: &Vec<Item>| row.get(jjj))
							{
								*nums.last_mut().unwrap() = *n;
							} else {
								break;
							}
						}
						let l: usize = (*l).try_into().unwrap();
						jj += l;
					} else {
						jj += 1;
					}
				}
			}
			if let [a, b] = nums[..] {
				sum += a * b;
			}
		}
	}
	println!("{sum}");
}

fn parse_matrix(lines: std::io::Lines<std::io::BufReader<std::fs::File>>) -> Vec<Vec<Item>> {
	lines.map(|line| line.unwrap()).map(parse_row).collect()
}

fn parse_row(row: String) -> Vec<Item> {
	let mut row = Vec::from_iter(row.chars().map(|c| {
		if let Some(digit) = c.to_digit(10) {
			Item::Number {
				n: digit.into(),
				l: 1,
			}
		} else if c == '.' {
			Item::Point
		} else {
			Item::Symbol
		}
	}));

	for i in (0..row.len()).rev() {
		let Some(Item::Number { n: np, l: lp }) = row.get(i + 1).cloned() else {
			continue;
		};
		let Some(Item::Number { n, l }) = row.get_mut(i) else {
			continue;
		};
		*n = *n * 10u64.pow(lp) + np;
		*l = lp + 1;
	}

	row
}
