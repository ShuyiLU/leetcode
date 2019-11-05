/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return vector<int>{};
		vector<int> res;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			int ma = INT_MIN;
			int n = q.size();
			for(int i=0; i<n; i++){
				TreeNode* tmp = q.front();
				q.pop();
				if(tmp->val > ma) ma = tmp->val;
				if(tmp->left != NULL) q.push(tmp->left);
				if(tmp->right != NULL) q.push(tmp->right);
			}
			res.push_back(ma);
		}
		return res;
    }
};
