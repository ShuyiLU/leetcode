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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return vector<vector<int> >{};
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        vector<vector<int> > res;
        while(!q.empty()){
        	TreeNode* node = q.front().first;
        	int level = q.front().second;
        	q.pop();
    
			if(node->left != NULL) q.push(make_pair(node->left, level+1));
			if(node->right != NULL) q.push(make_pair(node->right, level+1));
			
			if(level >= res.size()) res.push_back(vector<int>{});
			res[level].push_back(node->val);
		}
		for(int i=0; i<res.size(); i++){
			if(i%2 == 1){
				for(int j=0; j<res[i].size()/2; j++) swap(res[i][j], res[i][res[i].size()-1-j]);
			}
		}
		return res;
    }
};
