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
        while(root!=NULL || !st.empty()){  //����������������ڵ㶼��ջ 
        	while(root!=NULL){
        		st.push(root);
        		root = root->left;
			}
			root = st.top();  //����ڵ㣬��֤����ջ�ҽڵ�ǰ�ȳ�root 
			st.pop();
			res.push_back(root->val);
			root = root->right;  //�ҽڵ㲻Ϊ��ʱ����һ����ջ 
		}
		return res;
    }
};
