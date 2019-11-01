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
    int res = 0;
    int longestConsecutive(TreeNode* root) {
        longestLength(root);
        return res;
    }
    
    int longestLength(TreeNode* root){
        if(root == NULL) return 0;
        int l=1, r=1;
        if(root->left != NULL && root->val+1 == root->left->val) l = longestLength(root->left) + 1;
        else longestLength(root->left);
        if(root->right != NULL && root->val+1 == root->right->val) r = longestLength(root->right) + 1;
        else longestLength(root->right);
        res = max(res, max(l,r));
       // cout << root->val << " " << max(l,r) << endl;
        return max(l, r);
    }
};