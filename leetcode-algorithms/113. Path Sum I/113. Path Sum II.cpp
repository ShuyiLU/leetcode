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
	vector<int> tmp;
	vector<vector<int> > res;
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
    	if(root == NULL) return res;
    	findSum(root, sum, 0, tmp, res);
    	return res;
        
    }
    
    void findSum(TreeNode* root, int sum, int cur_sum, vector<int> &tmp, vector<vector<int> > &res){
    	cur_sum += root->val;
    	tmp.push_back(root->val); 
		if(root->left == NULL && root->right == NULL){
    		if(cur_sum == sum) res.push_back(tmp);
    		tmp.pop_back();
    		cur_sum = cur_sum - root->val;
    		return;
		}
		
		if(root->left != NULL) {
		//	tmp.push_back(root->left->val);
			findSum(root->left, sum, cur_sum, tmp, res);
		}
		
		
		if(root->right != NULL) {
		//	tmp.push_back(root->right->val);
			findSum(root->right, sum, cur_sum, tmp, res);
		}	
		
		cur_sum = cur_sum - root->val;
		tmp.pop_back();	
	}
};
