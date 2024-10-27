class Solution {
public:
    int m,n;
    int solve(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&d){
        if(i>=n || j>=m){
            return 0;
        }
        
        if(matrix[i][j]==0){
            return 0;
        }
        
        
        if(d[i][j]!=-1){
            return d[i][j];
        }
        
        int right=solve(matrix,i,j+1,d);
        int dia=solve(matrix,i+1,j+1,d);
        int below=solve(matrix,i+1,j,d);
        
        
        return d[i][j]=1+min({right,dia,below});
        
        
    }
    
    
    
    int countSquares(vector<vector<int>>& matrix) {
        
         n=matrix.size();
     m=matrix[0].size();
        
        vector<vector<int>>d(n+1,vector<int>(m+1,-1));
        long long result=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    result+=solve(matrix,i,j,d);
                }
            }
        }
        
        
        return result;
        
    }
};