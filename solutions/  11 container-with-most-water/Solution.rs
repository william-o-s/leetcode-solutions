use std::cmp::{min,max};

impl Solution {
    /// https://leetcode.com/problems/container-with-most-water/solutions/3701708/best-method-c-java-python-beginner-friendly
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left: usize = 0;
        let mut right: usize = height.len() - 1;
        let mut max_area = 0;

        while left < right {
            let curr_area = min(height[left], height[right]) * ((right - left) as i32);
            max_area = max(max_area, curr_area);

            if (height[left] < height[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }

        max_area
    }
}