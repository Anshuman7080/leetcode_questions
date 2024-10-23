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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        
        vector<int>sum;
        
        while(!q.empty()){
            int current_sum=0;
            int n=q.size();
            
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                
                current_sum+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                
                
                if(temp->right){
                    q.push(temp->right);
                }
                
                
                
                
                
            }
            
            
            sum.push_back(current_sum);
            
        }
        
        
        q.push(root);
        root->val=0;
        
        int i=1;
        while(!q.empty()){
            int n=q.size();
            
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                
                int siblingsum= curr->left !=NULL ? curr->left->val:0;
                siblingsum+=curr->right!=NULL  ? curr->right->val :0;
                
                
                if(curr->left){
                    curr->left->val=sum[i]-siblingsum;
                    q.push(curr->left);
                }
                
                
                if(curr->right){
                    curr->right->val=sum[i]-siblingsum;
                    q.push(curr->right);
                }
                
            }
            i++;
        }
        
        return root;
    }
};