class Solution:
    def integerBreak(self, n: int) -> int:
        N: int = 52
        memo: list[int] = [0] * (N + 1)
        memo[2] = 1
        memo[3] = 2
        memo[4] = 4
        memo[5] = 6
        memo[6] = 9

        i = 7
        while i <= n:
            memo[i] = 3 * memo[i - 3]
            i += 1
        
        return memo[n]
