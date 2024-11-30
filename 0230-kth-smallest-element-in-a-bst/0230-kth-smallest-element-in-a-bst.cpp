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
public:
    void traverse(TreeNode* root ,int k,vector<int>&arr){

         if(!root){
             return ;
         }
        
       
        
        traverse(root->left,k,arr);
        
       arr.push_back(root->val);
        
        traverse(root->right,k,arr);
         
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int>arr;
      traverse(root,k,arr);
      return arr[k-1];
    
        
        
        
    }
};