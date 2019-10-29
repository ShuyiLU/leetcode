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
    int findClosestLeaf(TreeNode* root, int k) {
        TreeNode* n = find(root, k);
        queue<TreeNode*> q;
        int res = -1;
        q.push(n);
        while(!q.empty()){
        	TreeNode* c = q.front();
        	q.pop();
        	if(c->left == NULL && c->right == NULL){
        		res = c->val;
        		break;
			}
			if(c->left != NULL) q.push(c->left);
			if(c->right != NULL) q.push(c->right);
		}
		return res;
    }
    TreeNode* find(TreeNode* root, int k){
    	if(root == NULL) return NULL;
    	if(root->val == k) return root;
    	if(find(root->left, k) != NULL) return find(root->left, k);
    	return find(root->right, k);
	}
};

class Solution {
public:
	map<int, vector<int> > mp;
	
    int findClosestLeaf(TreeNode* root, int k) {
    	if(root == NULL) return -1;
    	if(root->left == NULL && root->right == NULL) return k;
    	buildGraph(root, NULL);
    	queue<int> q;
    	set<int> visited;
    	q.push_back(k);
    	visited.insert(k);
    	while(!q.empty()){
    		int f = q.front();
    		q.pop();
    		if(root->val != f && mp[f].size() == 1) return f;  //leaf只有一个边 
    		int n=mp[f].size();
    		for(int i=0; i<n; i++){
    			int v = mp[f][i];
    			if(visited.count(v) > 0) continue;
    			visited.insert(v);
    			q.push(v);
			}
		}
		return -1;
    }
    
    void buildGraph(TreeNode* root, TreeNode* parent){
    	if(root == NULL) return;
    	buildGraph(root->left, root);
    	buildGraph(root->right, root);
    	if(parent != NULL){
    		mp[parent->val].push_back(root->val);
    		mp[root->val].push_back(parent->val);
		}
    	
	}
    
};
