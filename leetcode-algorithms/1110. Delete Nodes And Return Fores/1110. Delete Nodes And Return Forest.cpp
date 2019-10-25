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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    	vector<TreeNode*> r;
    	r.push_back(root);
        for(int i=0; i<to_delete.size(); i++){
        	for(int j=0; j<r.size(); j++){
        		TreeNode* fa = NULL;
        		TreeNode* node = findNode(r[j], to_delete[i], fa);
        		if(node != NULL){
        			if(node->left != NULL) r.push_back(node->left);
					if(node->right != NULL) r.push_back(node->right);
					if(node->val == r[j]->val){
						swap(r[j], r[r.size()-1]);
						r.pop_back();
					}
					else{
						if(fa->left == node) fa->left = NULL;
						else if(fa->right == node) fa->right = NULL;
					}
				//	delete node;
					break;
				}
			}       	       	
		}
		return r;
    }
    
    TreeNode* findNode(TreeNode* root, int n, TreeNode* &fa){
    	if(root == NULL) return NULL;
    	if(root->val == n) return root;
    	if(root->left != NULL &&root->left->val == n){
    		fa = root;
    		return root->left;
		}
		else if(root->right != NULL && root->right->val == n){
			fa = root;
			return root->right;
		}
    	TreeNode* t = findNode(root->left, n, fa);
    	if(t != NULL) return t;
    	return findNode(root->right, n, fa);
	}
	
	
	TreeNode* findPa(TreeNode* root, TreeNode* n){
		if(root == NULL) return NULL;
		if(root->left == n || root->right == n) return root;
		TreeNode* p = findPa(root->left, n);
		if(p != NULL) return p;
		return findPa(root->right, n);
	}
	
};
