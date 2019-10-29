#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
	bool flag = true;
    bool isBalanced(TreeNode* root) {
    	if (root == NULL) flag = true;
    	else{
    		if(abs(getHeight(root->left) - getHeight(root->right)) <= 1) {
				flag = isBalanced(root->left) && isBalanced(root->right);
			}
			else flag = false;	
		}
        
        return flag;
    }
    int getHeight(TreeNode* root){
    	if(root == NULL) return 0;
    	else{
    		return max(getHeight(root->left), getHeight(root->right)) + 1;
		}
	}
};

int main(){
}
