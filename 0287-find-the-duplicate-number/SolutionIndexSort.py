class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        '''
        Attempt to place each number in its correct place - if you find a number
        already in its correct place, that is the duplicate

        Time complexity: O(N), either each number is already at the correct place, some number is placed into its correct place, or the duplicate is found
        Space complexity: O(1), only curr, swap, and keep_moving
        '''

        i = 0
        while i < len(nums):
            n = nums[i]

            # If element already in correct place, move on
            if nums[i] == i + 1:
                i += 1
                continue

            # Number to swap with is already correct, duplicate found
            if n == nums[n - 1]:
                return n

            # Element is in the wrong place, swap with whichever number is in its place
            nums[i] = nums[n - 1]
            nums[n - 1] = n

        return 0
