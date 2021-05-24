/* Problem detect-capital
 * https://www.leetcode.com/problems/detect-capital
 */

impl Solution {
  pub fn detect_capital_use(word: String) -> bool {
    
    let mut it = word.chars()
                     .map(char::is_lowercase);
    match it.next() {
        Some(true) => it.all(|lw| lw),
        Some(false) => {
            match it.next() {
                Some(slw) => it.all(|lw| lw == slw),
                None => true,
            }
        },
        None => true,   
    }
  }
}
