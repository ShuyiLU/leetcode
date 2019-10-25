#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
private:
	int max = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        getPath(root, max);
        return max;
    }
    
    int getPath(TreeNode* root, int& max){
    	int l = 0;
    	int r = 0;
    	if(root->left != NULL && root->left->val == root->val)
    		l = 1 + getPath(root->left, max);
    	else if(root->left != NULL) getPath(root->left, max);
    	if(root->right != NULL && root->right->val == root->val)
    		r = 1 + getPath(root->right, max);
    	else if(root->right != NULL) getPath(root->right, max);
    	
    	if(l+r > max) max = l + r;
    	
    	if(root->left == NULL && root->right != NULL) return r;
    	if(root->left != NULL && root->right == NULL) return l;
    	if(root->left == NULL && root->right == NULL) return 0;
    	
    	if(l > r) return l;
    	else return r;
		
	} 
    
};

int main(){
}
