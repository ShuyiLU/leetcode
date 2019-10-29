#include<iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	bool flag;
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) flag = true;
        
		else if((p == NULL && q != NULL) || (p != NULL && q == NULL)) flag = false;
		
		else if(p->val != q->val) flag = false;
		
		else if(p->val == q->val){
        	flag = (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) );
		}
		return flag;
    }
};
