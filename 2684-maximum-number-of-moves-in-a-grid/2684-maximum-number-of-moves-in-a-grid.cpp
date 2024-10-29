class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, int m, int n, vector<vector<int>>& memo) {
        if (row < 0 || row >= m || col >= n) {
            return 0;
        }
        if (memo[row][col] != -1) {
            return memo[row][col];
        }
        int diagonal = 0, front = 0, diagonal2 = 0;
        if (row - 1 >= 0 && col + 1 < n && grid[row - 1][col + 1] > grid[row][col]) {
            diagonal = solve(grid, row - 1, col + 1, m, n, memo);
        }
        if (col + 1 < n && grid[row][col + 1] > grid[row][col]) {
            front = solve(grid, row, col + 1, m, n, memo);
        }
        if (row + 1 < m && col + 1 < n && grid[row + 1][col + 1] > grid[row][col]) {
            diagonal2 = solve(grid, row + 1, col + 1, m, n, memo);
        }
        memo[row][col] = 1 + max({diagonal, front, diagonal2});
        return memo[row][col];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_moves = 0;
        vector<vector<int>> memo(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            int moves = solve(grid, i, 0, m, n, memo);
            max_moves = max(moves, max_moves);
        }
        return max_moves-1;
    }
};
