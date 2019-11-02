/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        return dfs(root, target).second;
    }
private:
    pair<double,int> dfs(TreeNode* root, double target) {
        if (!root) return {1e18, 0};
        pair<double,int> mn={abs(root->val-target), root->val};
        mn=min(mn, dfs(root->left, target));
        mn=min(mn, dfs(root->right, target));
        return mn;
    }
};