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
    int maxPathSum(TreeNode* root) {
        ans=root->val;
        dfs(root);
        return ans;
    }
private:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int lp=max(0, dfs(root->left));
        int rp=max(0, dfs(root->right));
        ans=max(ans, lp+rp+root->val);
        return max(lp, rp)+root->val;
    }
    int ans;
};