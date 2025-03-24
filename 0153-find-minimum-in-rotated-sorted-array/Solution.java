class Solution {
    /**
     * Find inflection point via binary search
     *
     *  Sorted array comparison: a < b < c < d < e
     * Rotated array comparison: d < e > a < b < c
     *               Inflection:     ^
     *
     * References:
     * - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solutions/158940/beat-100-very-simple-python-very-detailed-explanation
     * */
    public int findMin(int[] nums) {
        int r = nums.length - 1;
        if (r == 0 || nums[0] < nums[r])
            return nums[0];

        // Converge on minimum index; thus prefer l < r over l <= r
        int l = 0;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                // Minimum must occur somewhere to the right of mid since mid is a rotated value
                l = mid + 1;
            } else {
                // Minimum must occur either at mid or below mid; we cannot discard mid
                r = mid;
            }
        }

        // Pointers have converged on minimum
        return nums[l];
    }

    public static void main(String[] args) {
        int[] arr1 = {4,5,6,7,0,1,2};
        System.out.printf("Minimum: %d%n", new Solution().findMin(arr1));
        int[] arr2 = {0,1,2,4,5,6,7};
        System.out.printf("Minimum: %d%n", new Solution().findMin(arr2));
        int[] arr3 = {3,4,5,1,2};
        System.out.printf("Minimum: %d%n", new Solution().findMin(arr3));
        int[] arr4 = {11,13,15,17};
        System.out.printf("Minimum: %d%n", new Solution().findMin(arr4));
        int[] arr5 = {1,2};
        System.out.printf("Minimum: %d%n", new Solution().findMin(arr5));
        int[] arr6 = {2,1};
        System.out.printf("Minimum: %d%n", new Solution().findMin(arr6));
        int[] arr7 = {4,5,1,2,3};
        System.out.printf("Minimum: %d%n", new Solution().findMin(arr7));
    }
}