class Solution:
    def canPartition(self, nums: List[int], i=0, sum1=0, sum2=0) -> bool:
        '''
        Brute-force: either assign i-th number to sum1 or sum2
        '''
        if i >= len(nums): return sum1 == sum2
        return (
            self.canPartition(nums, i+1, sum1+nums[i], sum2)
            or self.canPartition(nums, i+1, sum1, sum2+nums[i])
        )
