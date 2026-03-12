class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        '''
        concept:
        prefix[j+1] - prefix[i] = k
        prefix[j+1] - k = prefix[i]

        logic:
        you increase the length of the subarray one index at a time
        if you find a prefix[i], then that is a contiguous subarray that is always
            a smaller subset of prefix[j+1]
            e.g.,                 a b c d e f g h i
              prefix[i] could be:[       ]
            prefix[j+1] could be:[               ]
               then, subarray is:        [       ]
        '''
        # Edge case: empty array
        if not nums:
            return 0

        # Compute prefix sum
        prefix_count = { 0: 1 } # Accounts for prefix sums already equal to k, i.e., prefix sum - k = prefix sum - prefix sum = 0
        prefix_sum = 0
        total = 0
        for num in nums:
            prefix_sum += num
            if (prefix_sum - k) in prefix_count:
                total += prefix_count[prefix_sum - k]
            prefix_count[prefix_sum] = prefix_count.get(prefix_sum, 0) + 1

        return total
