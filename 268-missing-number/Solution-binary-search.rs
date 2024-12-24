impl Solution {
    /// https://leetcode.com/problems/missing-number/solutions/69786/3-different-ideas-xor-sum-binary-search-java-code
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        nums.sort();

        let (mut left, mut right) = (0, nums.len() as i32);
        let mut mid;
        while left < right {
            mid = (left + right) / 2;
            if (nums[mid as usize] > mid) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        left
    }
}