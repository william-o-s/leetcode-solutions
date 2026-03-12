impl Solution {
    /// https://leetcode.com/problems/missing-number/solutions/69786/3-different-ideas-xor-sum-binary-search-java-code
    ///
    /// Core concept: a XOR b XOR b == a
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        // nums has one number missing, but indexes never change
        // As one number is missing, the default index is the one provided if the number were present,
        // i.e., the last index
        let mut val = nums.len() as i32;

        for (i, num) in nums.iter().enumerate() {
            val ^= i as i32;
            val ^= num;
        }
        val
    }
}