#include<iostream>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return vector<int>{};
        stack<TreeNode*> st;
        while(root!=NULL || !st.empty()){  //遍历左子树，把左节点都入栈 
        	while(root!=NULL){
        		st.push(root);
        		root = root->left;
			}
			root = st.top();  //出左节点，保证在入栈右节点前先出root 
			st.pop();
			res.push_back(root->val);
			root = root->right;  //右节点不为空时，下一次入栈 
		}
		return res;
    }
};
