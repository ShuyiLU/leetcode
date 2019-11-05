#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return NULL;
        if(root->left==NULL && root->right == NULL){
        	if(root->val == 1) return root;
        	else return NULL;
		}
		if(!haveOne(root->left)) root->left = NULL;
        else root->left = pruneTree(root->left);
		if(!haveOne(root->right)) root->right = NULL;
        else root->right = pruneTree(root->right);
		return root;
    }
    
    
    bool haveOne(TreeNode* node){
    	if(node == NULL) return false;
        if(node->val == 1) return true;
    	if(node->left == NULL && node->right == NULL){
    		if(node->val == 1) return true;
    		else return false;
		}
		return haveOne(node->left) || haveOne(node->right);
	}
    
};
