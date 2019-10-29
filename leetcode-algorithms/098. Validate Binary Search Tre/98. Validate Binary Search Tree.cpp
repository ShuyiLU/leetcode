#include<iostream>
#include<vector>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
class Solution {
private:
	vector<int> l;
	vector<int> r;
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long min, long max){
    	if(root == NULL) return true;
    	if(root->val <= min || root->val >= max) return false;
    	return(isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max));
	}
    
};
*/

class Solution {
private:
	vector<int> v;
public:
    bool isValidBST(TreeNode* root) { 
    	if(root == NULL) return true;
        pre(root);
        for(int i=0; i<v.size()-1; i++){
        	if(v[i] >= v[i] + 1) return false;
		}
		return true;
    }
    
    void pre(TreeNode* root) {
    	if(root == NULL) return;
    	pre(root->left);
    	v.push_back(root->val);
    	pre(root->right);
	}   
    
};

int main(){
}
