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
    
    TreeNode* findMini(TreeNode* root){
        if(root==NULL){
            return root;
        }
       
        while(root->left){
            root=root->left;
        }
        
        return root;
        
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
            
        }
        
        if(root->val==key){
            if(!root->left){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else if(!root->right){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }else{
                
                int mini=findMini(root->right)->val;
                root->val=mini;
                root->right=deleteNode(root->right,mini);
                
                return root;
            }
            
            
            
        }else if(root->val >key){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }
        
        return root;
        
    }
};