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
    int largestBSTSubtree(TreeNode* root) {
        if(root == NULL) return 0;
		if(isValid(root, INT_MIN, INT_MAX)) return count(root);
		return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
	
	bool isValid(TreeNode* root, int mn, int mx){
		if(root == NULL) return true;
		if(root->val <= mn || root->val >= mx) return false;
		return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
	}
	
	int count(TreeNode* root){
		if(root == NULL) return 0;
		return count(root->left) + count(root->right) + 1;
	}
	
	
};
