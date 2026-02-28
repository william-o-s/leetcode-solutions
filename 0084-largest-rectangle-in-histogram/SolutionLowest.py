class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        '''
        Store the furthest rectangle possible left-right for each bar
        '''
        if not heights or len(heights) == 0:
            return 0

        lessFromLeft = [0 for _ in range(len(heights))]
        lessFromRight = [0 for _ in range(len(heights))]
        lessFromRight[len(heights) - 1] = len(heights)
        lessFromLeft[0] = -1

        # Record the index of the first bar lower than the current bar
        # DP approach reuses the computations of previous bars
        # i.e., the smallest bar left of the current, is the smallest bar
        #       of the previous computations still larger than current
        for i in range(1, len(heights)):
            p = i - 1
            while p >= 0 and heights[p] >= heights[i]:
                p = lessFromLeft[p]
            lessFromLeft[i] = p

        print(lessFromLeft)

        for i in range(len(heights) - 2, -1, -1):
            p = i + 1
            while p < len(heights) and heights[p] >= heights[i]:
                p = lessFromRight[p]
            lessFromRight[i] = p

        print(lessFromRight)

        maxArea = 0
        for i in range(len(heights)):
            maxArea = max(maxArea, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1))
        return maxArea
