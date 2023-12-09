/* Year 2023 - Day 9
 * https://adventofcode.com/2023/day/9
 */

pub fn main() {
	let series = parse_series("input_small.txt");
	part1(&series, Some(114));
	part2(&series, Some(2));

	let series = parse_series("input.txt");
	part1(&series, Some(1987402313));
	part2(&series, Some(900));
}

fn part1(series: &[Vec<i64>], expected: Option<i64>) {
	let solution = series
		.iter()
		.map(|series| extrapolate_next(&mut series.to_owned()))
		.sum::<i64>();
	println!("{solution}");
	if let Some(expected) = expected {
		assert_eq!(solution, expected);
	}
}

fn part2(series: &[Vec<i64>], expected: Option<i64>) {
	let solution = series
		.iter()
		.map(|series| extrapolate_prev(&mut series.to_owned()))
		.sum::<i64>();
	println!("{solution}");
	if let Some(expected) = expected {
		assert_eq!(solution, expected);
	}
}

fn extrapolate_next(series: &mut [i64]) -> i64 {
	if series.iter().all(|number| *number == 0) {
		return 0;
	}
	for i in 0..(series.len() - 1) {
		series[i] = series[i + 1] - series[i];
	}
	let (last, series) = series.split_last_mut().unwrap();
	*last + extrapolate_next(series)
}

fn extrapolate_prev(series: &mut [i64]) -> i64 {
	if series.iter().all(|number| *number == 0) {
		return 0;
	}
	for i in (1..(series.len())).rev() {
		series[i] -= series[i - 1];
	}
	let (first, series) = series.split_first_mut().unwrap();
	*first - extrapolate_prev(series)
}

fn parse_series(file: &str) -> Vec<Vec<i64>> {
	let input = std::io::BufReader::new(std::fs::File::open(file).unwrap());
	use std::io::BufRead;
	input
		.lines()
		.map(|line| {
			line.unwrap()
				.split_ascii_whitespace()
				.map(|number| number.parse().unwrap())
				.collect()
		})
		.collect()
}
