# taken from: https://neetcode.io/problems/longest-consecutive-sequence/solution

def longestConsecutive(nums: list[int]) -> int:
    numSet = set(nums)
    longest = 0

    for num in numSet:
        if (num - 1) not in numSet:
            length = 1
            while (num + length) in numSet:
                length += 1
            longest = max(length, longest)
    return longest


def main():
    nums = []
    for i in range(1, 50_000 + 1):
        nums.append(i)

    longestConsecutive(nums)
