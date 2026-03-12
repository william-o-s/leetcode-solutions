impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut res = vec![1; n];
        let mut left = 1;
        let mut right = 1;

        for i in 0..n {
            res[i] = left;
            left *= nums[i];
        }
        for j in (0..n).rev() {
            res[j] *= right;
            right *= nums[j];
        }

        res
    }
}