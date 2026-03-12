impl Solution {
    /// https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/66140/my-concise-o-m-n-java-solution
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        if matrix.is_empty() || matrix[0].is_empty() {
            return false;
        }

        let (mut row, mut col) = (0, matrix[0].len() - 1);
        while col >= 0 && row < matrix.len() {
            if target == matrix[row][col] {
                return true;
            }
            else if target > matrix[row][col] {
                row += 1;
            }
            else if target < matrix[row][col] && col > 0 {
                col -= 1;
            }
            else {
                break;
            }
        }
        false
    }
}