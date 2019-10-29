#include<iostream>
#include<queue>
#include<map>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getH(TreeNode* root, int h){
	if(root == NULL) return h;
	else return max(getH(root->left, h+1), getH(root->right, h+1));
}

int main(){
	
}
