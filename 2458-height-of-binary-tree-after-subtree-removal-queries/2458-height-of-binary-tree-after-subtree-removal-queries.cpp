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
    unordered_map<int, int> l, r, h;

    int calculateHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int left = calculateHeight(root->left);
        int right = calculateHeight(root->right);
        
        l[root->val] = left;
        r[root->val] = right;
        return max(left, right) + 1;
    }
    
    void solve(TreeNode* root, int maxa, int depth) {
        if (!root) return;
        h[root->val] = maxa;
        solve(root->left, max(maxa, depth + r[root->val]), depth + 1);
        solve(root->right, max(maxa, depth + l[root->val]), depth + 1);
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        calculateHeight(root);
        solve(root->left, r[root->val], 1);
        solve(root->right, l[root->val], 1);
        
        vector<int> ans;
        for (int query : queries) {
            ans.push_back(h[query]);
        }
        
        return ans;
    }
};
