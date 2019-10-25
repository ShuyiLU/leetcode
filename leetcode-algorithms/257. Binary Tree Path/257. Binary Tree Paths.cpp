#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
//	string st = "";
	vector<string> re;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
    	if(root == NULL) {
    		return re;
		}
        dfs(root, to_string(root->val));
    	return re;
    }
    
    void dfs(TreeNode* root, string st){
    	if(root->left == NULL && root->right == NULL) {
    		re.push_back(st);
		}
		if (root->left) {
      		dfs(root->left, st + "->" + to_string(root->left->val));
    	}
    	if (root->right) {
      		dfs(root->right, st + "->" + to_string(root->right->val));
      	}
    }
};

int main(){
	
}
