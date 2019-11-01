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
	map<int, vector<int> > mp;
	
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == NULL) return vector<int>{};
		vector<int> res;
		if(root->left == NULL && root->right == NULL){
			if(target == root && K==0){
				res.push_back(target->val);
				return res;
			}
			else return vector<int>{};
		}
		
		build(root, NULL);
		queue<int> q;
		set<int> visited;
		q.push(target->val);
		visited.insert(target->val);
		while(!q.empty()){
			//int f = q.front();
			//q.pop();
			if(K==0){
				break;
			}
			int n = q.size();
			for(int i=0; i<n; i++){
				int tmp = q.front();
				q.pop();
				for(int j=0; j<mp[tmp].size(); j++){
					if(visited.count(mp[tmp][j]) >0) continue;
					q.push(mp[tmp][j]);
					visited.insert(mp[tmp][j]);
				}
			}
			K--;
		}
		
		while(!q.empty()){
			res.push_back(q.front());
			q.pop();
		}
		return res;
    }
	
	void build(TreeNode* root, TreeNode* parent){
		if(root == NULL) return;
		build(root->left, root);
		build(root->right, root);
		if(parent != NULL){
			mp[parent->val].push_back(root->val);
			mp[root->val].push_back(parent->val);
		}
	}
	
	
	
	
	
};

