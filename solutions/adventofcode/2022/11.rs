/* Year 2022 - Day 11
 * https://adventofcode.com/2022/day/11
 */

use std::io::BufRead;

fn main() {
	let monkeys: Vec<_> = std::io::BufReader::new(std::io::stdin())
		.lines()
		.flatten()
		.map(|line| line.trim().to_owned())
		.filter(|line| !line.is_empty())
		.fold(Vec::default(), |mut monkeys, line| {
			match line.as_bytes()[0] {
				b'M' => monkeys.push((Monkey::default(), Vec::default())),
				b'S' => monkeys.last_mut().unwrap().1.extend(
					line[16..]
						.split(',')
						.map(|token| -> u64 { token.trim().parse().unwrap() }),
				),
				b'O' => {
					let monkey = &mut (monkeys.last_mut().unwrap().0);
					monkey.operation = match line.as_bytes()[21] {
						b'+' => MonkeyOperation::Add,
						b'-' => MonkeyOperation::Sub,
						b'*' => MonkeyOperation::Mul,
						b'/' => MonkeyOperation::Div,
						_ => panic!(),
					};
					monkey.operand = line[22..]
						.trim()
						.parse()
						.map(|token| MonkeyOperand::U64(token))
						.unwrap_or_default();
				}
				b'T' => {
					monkeys.last_mut().unwrap().0.module = line
						.split_ascii_whitespace()
						.next_back()
						.unwrap()
						.parse()
						.unwrap()
				}
				b'I' => {
					let monkey = &mut (monkeys.last_mut().unwrap().0);
					*match line.as_bytes()[3] {
						b't' => &mut monkey.positive,
						b'f' => &mut monkey.negative,
						_ => panic!(),
					} = line
						.split_ascii_whitespace()
						.next_back()
						.unwrap()
						.parse()
						.unwrap();
				}
				_ => panic!(),
			}
			monkeys
		});

	println!("{}", part1(&mut monkeys.clone()));
	println!("{}", part2(&mut monkeys.clone()));
}

#[derive(Default, Clone, Debug)]
struct Monkey {
	operation: MonkeyOperation,
	operand: MonkeyOperand,
	module: u64,
	positive: usize,
	negative: usize,
}

#[derive(Default, Clone, Debug)]
enum MonkeyOperation {
	#[default]
	NoOp,
	Add,
	Sub,
	Mul,
	Div,
}

#[derive(Default, Clone, Debug)]
enum MonkeyOperand {
	#[default]
	Old,
	U64(u64),
}

fn part1(monkeys: &mut [(Monkey, Vec<u64>)]) -> usize {
	common(monkeys, 20, u64::MAX, 3)
}

fn part2(monkeys: &mut [(Monkey, Vec<u64>)]) -> usize {
	common(
		monkeys,
		10000,
		monkeys
			.iter()
			.map(|(monkey, _)| monkey.module)
			.reduce(std::ops::Mul::mul)
			.unwrap(),
		1,
	)
}

fn common(monkeys: &mut [(Monkey, Vec<u64>)], rounds: usize, module: u64, divisor: u64) -> usize {
	let mut freq = Vec::from_iter(std::iter::repeat(0usize).take(monkeys.len()));

	for _ in 0..rounds {
		let mut distribution =
			Vec::from_iter(std::iter::repeat(Vec::default()).take(monkeys.len()));

		for (index, (monkey, items)) in monkeys.iter_mut().enumerate() {
			let monkey = &*monkey;

			items.append(&mut distribution[index]);

			for mut item in items.drain(..) {
				freq[index] += 1;

				let operand = match monkey.operand {
					MonkeyOperand::Old => item,
					MonkeyOperand::U64(operand) => operand,
				};

				item = match monkey.operation {
					MonkeyOperation::NoOp => panic!(),
					MonkeyOperation::Add => item + operand,
					MonkeyOperation::Sub => item - operand,
					MonkeyOperation::Mul => item * operand,
					MonkeyOperation::Div => item / operand,
				} % module / divisor;

				if item % monkey.module == 0 {
					&mut distribution[monkey.positive]
				} else {
					&mut distribution[monkey.negative]
				}
				.push(item);
			}
		}

		for (index, items) in distribution.into_iter().enumerate() {
			monkeys[index].1.extend(items);
		}
	}

	freq.sort();
	freq.into_iter()
		.rev()
		.take(2)
		.reduce(std::ops::Mul::mul)
		.unwrap()
}
