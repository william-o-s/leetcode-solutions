class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        '''
        interval: [x, y]
        newInterval: [a, b]

        Overlaps fully:
        x <= a && b <= y, i.e., [x a b y]
        Overlaps partially:
        x <= a && y <= b, i.e, [x a y b]
        a <= x && b <= y, i.e., [a x b y]
        No overlap:
        b < x || y < a, i.e., [a b x y] or [x y a b]
        '''

        result = []
        added = False
        for i, interval in enumerate(intervals):
            # Overlaps fully - merge and stop
            if interval[0] <= newInterval[0] and newInterval[1] <= interval[1]:
                result.extend(intervals[i:])
                added = True
                break

            # Non-overlapping - append and stop
            if newInterval[1] < interval[0]:
                # Append newInterval first
                result.append(newInterval)
                result.extend(intervals[i:])
                added = True
                break

            # Interval is before newInterval
            if interval[1] < newInterval[0]:
                # Append interval and continue
                result.append(interval)
                continue

            # Overlaps partially - make newInterval the merged interval
            newInterval = [min(interval[0], newInterval[0]), max(interval[1], newInterval[1])]

        if not added:
            result.append(newInterval)

        return result
