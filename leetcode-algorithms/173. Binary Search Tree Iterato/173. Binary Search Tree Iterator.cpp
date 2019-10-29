#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class BSTIterator {
private:
	stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        while(root){
        	st.push(root);
        	root = root -> left;
		}
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* next = st.top();
        TreeNode* cur = next->right;
        st.pop();
        while(cur){
        	st.push(cur);
        	cur = cur->left;
		}
		return next->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

