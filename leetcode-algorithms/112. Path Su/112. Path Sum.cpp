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
	int sumP = 0;
	vector<int> v;
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	if(root == NULL) return false;
    	sumPath(root, root->val);
       	for(int i=0; i<v.size(); i++){
       		if(v[i] == sum) return true;
	   	} 
	   	return false;
    }
    
    
    void sumPath(TreeNode* root, int sumP){
    	if(root -> left == NULL && root->right == NULL){
       		//sumP += root->val;
       		v.push_back(sumP);
       		//return v;
		}
		
	   		if(root->left != NULL) sumPath(root->left, sumP + root->left->val);
	   		if(root->right != NULL) sumPath(root->right, sumP + root->right->val);
	   	
	   	//return v;
	}
    
    
};


int main(){
	
}
