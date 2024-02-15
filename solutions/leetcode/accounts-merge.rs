/* Problem accounts-merge
 * https://www.leetcode.com/problems/accounts-merge
 */

struct Solution;

impl Solution {
	pub fn accounts_merge(accounts: Vec<Vec<String>>) -> Vec<Vec<String>> {
		let mut name_map = std::collections::HashMap::new();

		for account in accounts {
			let mut iter = account.into_iter();
			let name = iter.next().unwrap();
			let emails_groups: &mut Vec<std::collections::BTreeSet<String>> =
				name_map.entry(name).or_insert(Vec::new());

			let mut new_email_group = std::collections::BTreeSet::from_iter(iter);
			let mut index = 0;
			loop {
				let Some(email_group) = emails_groups.get(index) else {
					break;
				};
				if email_group.intersection(&new_email_group).any(|_| true) {
					new_email_group.extend(emails_groups.swap_remove(index));
				} else {
					index += 1;
				}
			}

			emails_groups.push(new_email_group);
		}

		name_map
			.into_iter()
			.flat_map(|(name, email_groups)| {
				email_groups.into_iter().map(move |emails| {
					let mut output = Vec::with_capacity(emails.len() + 1);
					output.push(name.clone());
					output.extend(emails);
					output
				})
			})
			.collect()
	}
}

pub fn main() {
	let input = vec![
		vec!["John", "johnsmith@mail.com", "john_newyork@mail.com"],
		vec!["John", "johnsmith@mail.com", "john00@mail.com"],
		vec!["Mary", "mary@mail.com"],
		vec!["John", "johnnybravo@mail.com"],
	];
	println!("{input:#?}");
	let output = Solution::accounts_merge(
		input
			.into_iter()
			.map(|row| row.into_iter().map(str::to_string).collect())
			.collect(),
	);
	println!("{output:#?}");
}
