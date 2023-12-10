/* Year 2023 - Day 10
 * https://adventofcode.com/2023/day/10
 */

const PIPES: [(char, [(usize, usize); 2]); 6] = [
	('|', [(2, 1), (0, 1)]),
	('-', [(1, 0), (1, 2)]),
	('L', [(2, 1), (1, 0)]),
	('J', [(2, 1), (1, 2)]),
	('7', [(0, 1), (1, 2)]),
	('F', [(0, 1), (1, 0)]),
];

pub fn main() {
	let maze = parse_maze("input_small.txt");
	let path = part1(&maze, None);
	part2(&maze, &path, None);

	let maze = parse_maze("input.txt");
	let path = part1(&maze, Some(6907));
	part2(&maze, &path, Some(541));
}

fn part1(maze: &[Vec<char>], expected: Option<u64>) -> Vec<(usize, usize)> {
	let (y, x) = maze
		.iter()
		.enumerate()
		.find_map(|(y, column)| {
			column
				.iter()
				.enumerate()
				.find_map(|(x, cell)| (*cell == 'S').then_some(x))
				.map(|j| (y, j))
		})
		.unwrap();
	let (solution, path) = None
		.or_else(|| {
			y.checked_sub(1)
				.and_then(|y_next| get_len_and_path(maze, (y_next, x), (y, x)))
		})
		.or_else(|| {
			x.checked_sub(1)
				.and_then(|x_next| get_len_and_path(maze, (y, x_next), (y, x)))
		})
		.or_else(|| get_len_and_path(maze, (y + 1, x), (y, x)))
		.or_else(|| get_len_and_path(maze, (y, x + 1), (y, x)))
		.map(|(len, path)| (len / 2, path))
		.unwrap();
	println!("{solution}");
	if let Some(expected) = expected {
		assert_eq!(solution, expected);
	}
	path
}

fn part2(maze: &[Vec<char>], path: &[(usize, usize)], expected: Option<usize>) {
	let starting_shape = get_starting_pipe_shape(path);
	let path = std::collections::BTreeSet::from_iter(path);
	let mut solution = 0;
	for (y, column) in maze.iter().enumerate() {
		for x in 0..column.len() {
			if path.contains(&(y, x)) {
				continue;
			}
			let mut up = 0;
			let mut down = 0;
			for (x, &cell) in column.iter().enumerate().take(x) {
				if !path.contains(&(y, x)) {
					continue;
				}
				let shape = match cell {
					'S' => starting_shape,
					shape => shape,
				};
				up += usize::from(matches!(shape, '|' | 'L' | 'J'));
				down += usize::from(matches!(shape, '|' | 'F' | '7'));
			}
			if up.min(down) % 2 == 1 {
				solution += 1;
			}
		}
	}
	println!("{solution}");
	if let Some(expected) = expected {
		assert_eq!(solution, expected);
	}
}

fn get_len_and_path(
	maze: &[Vec<char>],
	(mut y, mut x): (usize, usize),
	mut prev: (usize, usize),
) -> Option<(u64, Vec<(usize, usize)>)> {
	let mut len = 1;
	loop {
		match maze.get(y).and_then(|column| column.get(x)) {
			Some('S') => return Some((len, get_path(maze, prev, (y, x)))),
			Some('.') => return None,
			Some(shape) => {
				let Some(next) = get_next_coordinate(*shape, (y, x), prev) else {
					break;
				};
				prev = (y, x);
				(y, x) = next;
				len += 1;
			}
			_ => break,
		}
	}
	None
}

fn get_path(
	maze: &[Vec<char>],
	(mut y, mut x): (usize, usize),
	mut prev: (usize, usize),
) -> Vec<(usize, usize)> {
	let mut path = Vec::new();
	loop {
		path.push((y, x));
		let shape = maze[y][x];
		if shape == 'S' {
			break;
		}
		let next = get_next_coordinate(shape, (y, x), prev).unwrap();
		prev = (y, x);
		(y, x) = next;
	}
	path
}

fn get_next_coordinate(
	shape: char,
	(y, x): (usize, usize),
	prev: (usize, usize),
) -> Option<(usize, usize)> {
	get_next_delta(shape, get_delta((y, x), prev)).and_then(|(y_next_delta, x_next_delta)| {
		(y + 1)
			.checked_sub(y_next_delta)
			.zip((x + 1).checked_sub(x_next_delta))
	})
}

fn get_next_delta(shape: char, delta: (usize, usize)) -> Option<(usize, usize)> {
	PIPES
		.iter()
		.find_map(|(shape_reference, entries)| (shape == *shape_reference).then_some(entries))
		.and_then(|entries| {
			entries
				.iter()
				.enumerate()
				.find_map(|(i_entry, entry)| (delta == *entry).then_some(i_entry))
				.map(|i_entry| entries[(i_entry + 1) % 2])
		})
}

fn get_starting_pipe_shape(path: &[(usize, usize)]) -> char {
	let len = path.len();
	let a = get_delta(path[len - 1], path[0]);
	let b = get_delta(path[len - 1], path[len - 2]);
	PIPES
		.iter()
		.find_map(|(shape, [entry_a, entry_b])| {
			(a == *entry_a && b == *entry_b || a == *entry_b && b == *entry_a).then_some(shape)
		})
		.cloned()
		.unwrap()
}

fn get_delta((y, x): (usize, usize), (y_prev, x_prev): (usize, usize)) -> (usize, usize) {
	let y_delta = 1 + y - y_prev;
	let x_delta = 1 + x - x_prev;
	(y_delta, x_delta)
}

fn parse_maze(file: &str) -> Vec<Vec<char>> {
	let input = std::io::BufReader::new(std::fs::File::open(file).unwrap());
	use std::io::BufRead;
	input
		.lines()
		.map(|line| line.unwrap().chars().collect())
		.collect()
}
