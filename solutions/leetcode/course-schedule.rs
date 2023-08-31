/* Problem course-schedule
 * https://www.leetcode.com/problems/course-schedule
 */

struct Solution;

impl Solution {
	pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
		let num_courses = num_courses.try_into().unwrap();

		let mut depency_counters = vec![0usize; num_courses];
		let mut dependants_by_course = vec![std::collections::BTreeSet::new(); num_courses];

		for prerequisite in prerequisites {
			let dependent: usize = prerequisite[0].try_into().unwrap();
			let dependency: usize = prerequisite[1].try_into().unwrap();
			dependants_by_course[dependency].insert(dependent);
			depency_counters[dependent] += 1;
		}

		let mut fulfilled = Vec::from_iter(
			depency_counters
				.iter()
				.enumerate()
				.filter(|(_, depency_counter)| **depency_counter == 0)
				.map(|(index, _)| index),
		);

		while let Some(course) = fulfilled.pop() {
			for dependant in dependants_by_course[course].iter().copied() {
				depency_counters[dependant] -= 1;
				if depency_counters[dependant] == 0 {
					fulfilled.push(dependant);
				}
			}
		}

		depency_counters
			.into_iter()
			.all(|depency_counter| depency_counter == 0)
	}
}

pub fn main() {
	assert_eq!(true, Solution::can_finish(2, vec![vec![1, 0]]));
	assert_eq!(false, Solution::can_finish(2, vec![vec![1, 0], vec![0, 1]]));
}
