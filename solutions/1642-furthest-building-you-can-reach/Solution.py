import heapq

class Solution:
    '''Priority Queue solution:
    We need to store the tallest buildings climbed so far. Thus, we use a PQ of size=ladders.
    When the PQ size > ladders, that means that we can't climb that building with a ladder, instead
    using bricks. This keeps going.
    '''
    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        heap = []
        for i in range(len(heights) - 1):
            height_diff = heights[i+1] - heights[i]
            if height_diff > 0:
                heapq.heappush(heap, height_diff)
            if len(heap) > ladders:
                bricks -= heapq.heappop(heap)
            if bricks < 0:
                return i
        return len(heights) - 1