/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void solve(vector<int>arr,int& cnt){
        int count=0;
        int n=arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int min_index = i;
            for (int j = i + 1; j < n; ++j) {
                
                
                if (arr[j] < arr[min_index]) {
                    min_index = j; } 
                
            } 
            
            if (min_index != i) { 
                swap(arr[i], arr[min_index]);
                count++;
            } 
        }
        
        cnt+=count;
        
    }
public:
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*>q;
        
        
        q.push(root);
        
    int cnt=0;
        while(!q.empty()){
            
         int size=q.size();
            
        vector<int>arr;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                
                if(temp->left){
                    q.push(temp->left);
                    
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
                arr.push_back(temp->val);
                
            }
            
            solve(arr,cnt);
            
            
        }
        
        return cnt;
        
    }
};