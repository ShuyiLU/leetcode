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
private:
	vector<TreeNode* > v;	
public:
    TreeNode* increasingBST(TreeNode* root) {
        Inorder(root);
        TreeNode* p = new TreeNode(v[0]->val);
        TreeNode* h = p;
        for(int i=1; i<v.size(); i++){
        	h->left = NULL;
        	h->right = new TreeNode(v[i]->val);
        	h = h->right;
		}
		return p;
    }
    
    void Inorder(TreeNode* root){
    	if(root== NULL) return;
    	if(root->left != NULL) Inorder(root->left);	
	    v.push_back(root);
	    if(root->right != NULL) Inorder(root->right);
	}
	
};

int main(){
}
