class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0, r = len(height) - 1
        total = maxLeft = maxRight = 0
        while l < r:
            if height[l] <= height[r]:
                if height[l] >= maxLeft:
                    maxLeft = height[l]
                else:
                    total += maxLeft - height[l]
                l += 1
            else:
                if height[r] >= maxRight:
                    maxRight = height[r]
                else:
                    total += maxRight - height[r]
                r -= 1
        return total