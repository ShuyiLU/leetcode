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
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return 0;
    	int res = 0;
        isUniTree(root, res);
        return res;
    }   
    bool isUniTree(TreeNode* root, int &res){
    	bool l;
    	bool r;
    	if(root->left == NULL && root->right == NULL) {
    		res++;
    		return true;
		}
    	if(root->left == NULL && root->right != NULL){
    		r = isUniTree(root->right, res);
    		if(root->val == root->right->val && r){
    			res++;
    			return true;
			} 
    		else return false;
		}
		if(root->right == NULL && root->left != NULL){
			l = isUniTree(root->left, res);
    		if(root->val == root->left->val && l ) {
    			res++;
    			return true;
			}
    		else return false;
		}
		l = isUniTree(root->left, res);
    	r = isUniTree(root->right, res);
		if(l && r){
			if(root->left->val == root->val && root->right->val == root->val){
				res++;
				return true;
			} 
			else return false;
		}
		return false;
	}    
};



class Solution {		
public:
    int countUnivalSubtrees(TreeNode* root) {
    	int res = 0;
        isUniTree(root, res);
        return res;
    }
    
    
    bool isUniTree(TreeNode* root, int &res){
    	if(root == NULL) return true;
    	bool l = isUniTree(root->left, res);
    	bool r = isUniTree(root->right, res);
		if(l && r){
			if(root->left != NULL && root->val != root->left->val) return false;
			else if(root->right != NULL && root->val != root->right->val) return false;
			else{
				res++;
				return true;
			}
		}
		else return false;
	}
    
};




