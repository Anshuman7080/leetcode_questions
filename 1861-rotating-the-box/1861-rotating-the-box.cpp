class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int m = box.size();
        int n = box[0].size();
        
        for (int i = 0; i < m; i++) {
            int j = n - 1;
            int k = j;
            
            while (j >= 0) {
                k = j;
                if (box[i][j] == '.') {
                    while (k >= 0 && box[i][k] != '*' && box[i][k] != '#') {
                        k--;
                    }
                    if (k >= 0 && box[i][k] == '#') {
                        swap(box[i][k], box[i][j]);
                    }
                }
                j--;
            }
        }
        
        // Transpose of matrix
        vector<vector<char>> ans(n, vector<char>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = box[j][i];
            }
        }
        
        // Reverse each row of the transposed matrix
        for (int i = 0; i < n; i++) {
            int j = 0;
            int k = m - 1;
            
            while (j < k) {
                swap(ans[i][j], ans[i][k]);
                j++;
                k--;
            }
        }
        
        return ans;
    }
};
