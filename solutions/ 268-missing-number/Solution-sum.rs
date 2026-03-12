impl Solution {
    /// https://leetcode.com/problems/missing-number/solutions/4756696/beats100-easy-explained-java-c-c-python3-javascript-rust
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n = nums.len() as i32;
        let mut sum = n * (n + 1) / 2;
        for num in nums {
            sum -= num;
        }
        sum
    }
}