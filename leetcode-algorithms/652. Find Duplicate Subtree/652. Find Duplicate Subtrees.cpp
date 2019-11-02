class Solution {
public:	
	map<string, int> mp;
    vector<TreeNode*> res;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		if(root == NULL) return res;
		dfs(root);
		return res;
    }
	
	
	string dfs(TreeNode* root){
		if(root == NULL) return "*";
		string tmp = to_string(root->val) + dfs(root->left) + dfs(root->right);
		if(mp[tmp] == 1) res.push_back(root);
		mp[tmp] ++ ;
		return tmp;
	}
	
	
};
