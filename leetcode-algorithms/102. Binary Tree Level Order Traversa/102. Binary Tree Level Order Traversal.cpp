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
    vector<vector<int> > levelOrder(TreeNode* root) {
        if(root == NULL) return vector< vector <int> > {};
        queue <pair<TreeNode*, int> > q;
        pair<TreeNode*, int> p = make_pair(root, 0);
        q.push(p);
        vector<vector<int> > res;
        res.resize(1);
        while(!q.empty()){
        	pair<TreeNode*, int> t = q.front();
        	q.pop();
        	TreeNode* f = t.first;
        	int pos = t.second;
        	if(f->left != NULL) q.push(make_pair(f->left, pos+1));
        	if(f->right != NULL) q.push(make_pair(f->right, pos+1));
        	if(res.size() <= pos) res.push_back(vector<int>{});
        	res[pos].push_back(f->val);
			
		}
        return res;
    }
};
