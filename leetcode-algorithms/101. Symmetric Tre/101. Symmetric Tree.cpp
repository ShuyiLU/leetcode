#include<iostream>
using namespace std; 

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	bool Sym(TreeNode* r1, TreeNode* r2){
		if(r1 == NULL && r2 != NULL) return false;
        if(r2 == NULL && r1 != NULL) return false;
        if(r1->val != r2->val) return false;
        if(r1 == NULL && r2 == NULL) return true;
        return Sym(r1->left, r2->right) && Sym(r1->right, r2->left);
	}
	
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return Sym(root->left, root->right);
    }
};
