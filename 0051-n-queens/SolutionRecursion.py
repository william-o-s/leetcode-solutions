from collections import deque

class Solution:
    def isValid(self, nQueens: List[List[str]], row: int, col: int, n: int) -> bool:
        # Check if column had a queen
        for i in range(n):
            if nQueens[i][col] == 'Q':
                return False

        # Logic: since you're building row-by-row, you only
        #        need to check the previous row's diagonal,
        #        not further

        # Check if left-to-right diagonal had a queen
        i, j = row - 1, col - 1
        while i >= 0 and j >= 0:
            if nQueens[i][j] == 'Q':
                return False
            i -= 1
            j -= 1

        # Logic: why you can't combine these loops?
        #        The starting cell may have different diagonal
        #        lengths, e.g., starting from first column has
        #        no left diagonal but has right diagonal

        # Check if right-to-left diagonal had a queen
        i, j = row - 1, col + 1
        while i >= 0 and j < n:
            if nQueens[i][j] == 'Q':
                return False
            i -= 1
            j += 1

        return True

    def solve(self, res: List[List[str]], nQueens: List[List[str]], row: int, n: int):
        if row == n:
            res.append([''.join(row) for row in nQueens])
            return

        for col in range(n):
            if self.isValid(nQueens, row, col, n):
                nQueens[row][col] = 'Q'
                self.solve(res, nQueens, row + 1, n)
                nQueens[row][col] = '.'

    def solveNQueens(self, n: int) -> List[List[str]]:
        '''
        Build board row-by-row recursively, asserting a valid board
        before continuing.
        '''
        res = []
        nQueens = [['.'] * n for _ in range(n)]
        self.solve(res, nQueens, 0, n)
        return res
