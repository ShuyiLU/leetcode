#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
  
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) return -1;
        if(root->left == NULL && root->right == NULL) return root->val;
        q.push(root);
        int res = root->val;
        while(!q.empty()){
        //	TreeNode* n = q.front();
        //	q.pop();
        //	res = n->val;
        	res = q.front()->val;
        	int size = q.size();
        	for(int i=0; i<size; i++){
        		TreeNode* tmp = q.front();
        		q.pop();
        		if(tmp->left != NULL) q.push(tmp->left);
        		if(tmp->right != NULL) q.push(tmp->right);
			}
		}
		return res;
    }
};
