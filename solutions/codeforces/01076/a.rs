/* Contest 1076 - Problem A
 * https://codeforces.com/problemset/problem/1076/A
 */

fn main() {
    std::io::stdin()
    .read_line(&mut String::new())
    .unwrap_or_default();
    
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).unwrap_or_default();

    let (s, _) = buffer
        .trim()
        .chars()
        .chain("\0".chars())
        .collect::<Vec<char>>()
        .windows(2)
        .fold(
            (String::new(), true),
            |(s, d), sij| {
                let si = sij[0];
                let sj = sij[1];
                if si > sj && d {
                    (s, false)
                } else {
                    (s + &si.to_string(), d)
                }
            }
        );
    println!("{}", s);
}
