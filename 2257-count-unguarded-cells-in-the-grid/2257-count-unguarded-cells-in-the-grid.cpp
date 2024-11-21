class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 1));
        
        // Mark walls
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 0;
        }
        
        // Mark guards
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }
        
        // Mark the influence of guards
        for (const auto& guard : guards) {
            int a = guard[0];
            int b = guard[1];
            
            // Up
            for (int x = a - 1; x >= 0 && grid[x][b] != 0 && grid[x][b] != 2; x--) {
                grid[x][b] = 3;
            }
            
            // Down
            for (int x = a + 1; x < m && grid[x][b] != 0 && grid[x][b] != 2; x++) {
                grid[x][b] = 3;
            }
            
            // Left
            for (int y = b - 1; y >= 0 && grid[a][y] != 0 && grid[a][y] != 2; y--) {
                grid[a][y] = 3;
            }
            
            // Right
            for (int y = b + 1; y < n && grid[a][y] != 0 && grid[a][y] != 2; y++) {
                grid[a][y] = 3;
            }
        }
        
        // Count unguarded cells
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
