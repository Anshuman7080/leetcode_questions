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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;  
        
        queue<TreeNode*> q;
        vector<long long> vec;
        
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;
            
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                sum += temp->val;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            vec.push_back(sum);
        }
        
        sort(vec.begin(), vec.end(), greater<long long>());
        if (vec.size() < k) {
            return -1;
        }
        
        return vec[k - 1];
    }
};
