class Solution:
    def nthUglyNumber(self, n: int) -> int:
        queue = [1]
        p2 = p3 = p5 = 0
        for _ in range(1, n):
            next = min(queue[p2]*2, queue[p3]*3, queue[p5]*5)
            if queue[p2]*2 == next: p2 += 1
            if queue[p3]*3 == next: p3 += 1
            if queue[p5]*5 == next: p5 += 1
            queue.append(next)
        return queue[-1]


