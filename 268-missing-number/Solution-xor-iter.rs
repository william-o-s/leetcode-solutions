impl Solution {
    /// https://leetcode.com/problems/missing-number/solutions/1091802/rust-0ms-o-n-runtime-o-1-space-xor-solution
    ///
    /// Core concept: a XOR b XOR b == a
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        (1..=nums.len() as i32)
            .zip(nums.into_iter())
            .fold(0, |xor, (x, y)| xor ^ x ^ y)
    }
}