class Solution:
    def maxArea(self, height: List[int]) -> int:
        '''
        Two pointer approach:
        Each pointer is the largest seen bar from their respective directions
        relative to each other

        Advance the smaller of the two pointers
        Why? Because the tradeoff of moving forward is shorter length.
        '''

        l, r = 0, len(height) - 1
        largest = 0
        while l < r:
            largest = max(largest, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return largest
