class Solution:
    def canPartition(self, nums: List[int], i=0, sum1=0, sum2=0) -> bool:
        '''
        Properties:
        - Partitions can only be made if total sum is even
        - Only one partition with (total_sum / 2) needs to be found (since the other will have the same sum)
        '''

        @cache
        def subsetSum(s, i=0):
            '''
            DP: optimizing the brute-force by storing the sums with and without element
            '''

            if s == 0: return True
            if i >= len(nums) or s < 0: return False
            return subsetSum(s - nums[i], i+1) or subsetSum(s, i+1)
        total_sum = sum(nums)
        return total_sum & 1 == 0 and subsetSum(total_sum // 2)
