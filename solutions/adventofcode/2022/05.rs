/* Year 2022 - Day 5
 * https://adventofcode.com/2022/day/5
 */

fn main() {
	use std::io::BufRead;
	let mut stdin = std::io::BufReader::new(std::io::stdin());

	let n: usize = {
		let mut buffer = String::default();
		stdin.read_line(&mut buffer).unwrap();
		buffer.trim().parse().unwrap()
	};

	let stacks: Vec<_> = std::iter::from_fn(|| {
		let mut buffer = String::default();
		stdin.read_line(&mut buffer).unwrap();
		Some(Vec::from_iter(buffer.trim().chars()))
	})
	.take(n)
	.collect();

	let movements: Vec<_> = stdin
		.lines()
		.flatten()
		.map(|line| {
			let mut tokens = line.split_ascii_whitespace();
			(
				tokens.next().unwrap().parse().unwrap(),
				tokens.next().unwrap().parse::<usize>().unwrap() - 1,
				tokens.next().unwrap().parse::<usize>().unwrap() - 1,
			)
		})
		.collect();

	println!("{}", part1(&mut stacks.clone(), &movements));
	println!("{}", part2(&mut stacks.clone(), &movements));
}

fn part1(stacks: &mut [Vec<char>], movements: &[(usize, usize, usize)]) -> String {
	let mut aux = Vec::default();
	for (n, o, d) in movements {
		aux.extend(stacks[*o].drain((stacks[*o].len() - n)..).rev());
		stacks[*d].append(&mut aux);
	}
	String::from_iter(stacks.iter().map(|stack| stack.last().unwrap()))
}

fn part2(stacks: &mut [Vec<char>], movements: &[(usize, usize, usize)]) -> String {
	let mut aux = Vec::default();
	for (n, o, d) in movements {
		aux.extend(stacks[*o].drain((stacks[*o].len() - n)..));
		stacks[*d].append(&mut aux);
	}
	String::from_iter(stacks.iter().map(|stack| stack.last().unwrap()))
}
