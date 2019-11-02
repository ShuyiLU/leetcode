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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL || p == NULL) return NULL;
        TreeNode* ans = NULL;
        while( root != NULL){
            if(root->val > p->val){
                ans = root;
                root = root->left; //p is left child, find siblings in left subtree
            }
            else root = root->right;  //p is right child
        }
        return ans;
    }
};