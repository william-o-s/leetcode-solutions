from collections import deque

class Solution:
    def boardInvalid(self, board: List[List[bool]]) -> bool:
        '''
        Verifies if a board is valid by ensuring no two queens
        are on the same column or diagonal.
        It is assumed the board is formed row-by-row, so only one
        queen is present on every row.
        '''
        assert len(board) == len(board[0])
        n = len(board)

        # Check cols
        for col in range(n):
            col_total = sum(int(row[col]) for row in board)
            if col_total > 1:
                return True

        # Check each diagonal - first and last column
        for i in range(n):
            row, col = i, 0
            left_total = right_total = 0
            while row < n and col < n and left_total <= 1 and right_total <= 1:
                left_total += int(board[row][col])
                right_total += int(board[row][n - col - 1])
                row += 1
                col += 1
            if left_total > 1 or right_total > 1:
                return True

        # Check each diagonal - first row
        for j in range(1, n):
            row, col = 0, j
            left_total = right_total = 0
            while row < n and col < n and left_total <= 1 and right_total <= 1:
                left_total += int(board[row][col])
                right_total += int(board[row][n - col - 1])
                row += 1
                col += 1
            if left_total > 1 or right_total > 1:
                return True

        return False

    def solveNQueens(self, n: int) -> List[List[str]]:
        '''
        Build board row-by-row, asserting arc consistency
        before exploring an arrangement further.
        Explores in BFS fashion.

        Tradeoffs of iteration:
        - Non-constant space complexity due to copy of array
        '''
        empty_board = [[False for _ in range(n)] for _ in range(n)]

        queue = deque([(empty_board, 0)])
        results = []
        while queue:
            board, row_idx = queue.popleft()

            # If board is invalid, don't bother exploring
            if self.boardInvalid(board):
                continue

            # If next row index is beyond board, this is a valid config
            if row_idx == n:
                converted_board = [''.join('Q' if isQueen else '.' for isQueen in row) for row in board]
                results.append(converted_board)
                continue

            # Explore placing a queen at the current row index
            for i in range(n):
                new_board = [sublist[:] for sublist in board]
                new_board[row_idx][i] = True
                new_idx = row_idx + 1
                queue.append((new_board, new_idx))
        print(len(results))
        return results
