class Solution:
    def canPartition(self, nums: List[int], i=0, sum1=0, sum2=0) -> bool:
        '''
        - Partition only if sum is even
        - See if (sum // 2) exists as a possible sum
        - Check sums with number included and without
        - Use DP to store intermediate sums where dp[ith number][target sum]
        '''

        total_sum = sum(nums)
        if total_sum & 1: return False
        target_sum = total_sum // 2

        N = len(nums)
        # dp := dp[after checking i numbers][sum of j can be achieved]
        dp = [[False for _ in range(target_sum + 1)] for _ in range(N + 1)]

        # Every number has a sum of 0 if not included; vice versa for sum
        dp[0][0] = True
        for i in range(1, N + 1):
            dp[i][0] = True
        for j in range(1, target_sum + 1):
            dp[0][j] = False

        # For each number, record the sum after including or excluding it
        for i in range(1, N + 1):
            for j in range(1, target_sum + 1):
                dp[i][j] = dp[i-1][j]   # Initialised with excluding current number
                if j >= nums[i-1]:
                    dp[i][j] |= dp[i-1][j-nums[i-1]]    # OR merge on whether it was possible to achieve required target sum (less current number) in previous iteration

        return dp[N][target_sum]
