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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* node = find(root, x);
        int l = count(node->left, x);
        int r = count(node->right, x);
        return max(max(l,r), n-l-r-1) > n/2;
    }
    
    TreeNode* find(TreeNode* root, int x){
    	if(root == NULL) return NULL;
    	if(root->val == x) return root;
    	TreeNode* p1 = find(root->left, x);
    	if(p1 != NULL) return p1;
    	return find(root->right,x);
	}
	
	int count(TreeNode* node, int x){
		if(node == NULL) return 0;
		int l = count(node->left, x);
		int r = count(node->right, x);
        return l+r+1;
	}
	
};
