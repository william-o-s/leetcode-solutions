class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        left = [0] * n
        right = [0] * n
        left[0] = right[n-1] = 1

        # Create left multiply array
        for i in range(1, n):
            left[i] = left[i-1] * nums[i-1]
        # Create right multiply array
        for j in range(n-2, -1, -1):
            right[j] = right[j+1] * nums[j+1]
        # Create result
        for k in range(n):
            res[k] = left[k] * right[k]
        return res
