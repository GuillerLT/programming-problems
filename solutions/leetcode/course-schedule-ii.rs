/* Problem course-schedule-ii
 * https://www.leetcode.com/problems/course-schedule-ii
 */

struct Solution;

impl Solution {
	pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
		let num_courses = num_courses as usize;
		let mut dependents = vec![Vec::with_capacity(num_courses); num_courses];
		let mut remainings = vec![0; num_courses];
		let mut next_courses = std::collections::BTreeSet::new();
		next_courses.extend(0..num_courses);
		for prerequisite in prerequisites {
			let dependent = prerequisite[0] as usize;
			let dependency = prerequisite[1] as usize;
			dependents[dependency].push(dependent);
			remainings[dependent] += 1;
			next_courses.remove(&dependent);
		}
		let mut ordered_courses = Vec::with_capacity(num_courses);
		while let Some(next_course) = next_courses.pop_first() {
			ordered_courses.push(next_course as i32);
			for dependent in dependents[next_course].drain(..) {
				remainings[dependent] -= 1;
				if remainings[dependent] == 0 {
					next_courses.insert(dependent);
				}
			}
		}
		if ordered_courses.len() != num_courses {
			ordered_courses.clear();
		}
		ordered_courses
	}
}

fn main() {}
