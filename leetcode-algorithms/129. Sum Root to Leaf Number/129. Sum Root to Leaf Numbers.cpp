 #include<iostream>
 #include<vector>
 
 using namespace std;
 
 struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0)
    }
    
    int DFS(TreeNode* root, int &k){
    	if(root == NULL) return 0; 
    	k = k*10 + root->val;
		if(root->left == NULL && root->right == NULL) return k;
		return DFS(root->left, k) + DFS(root->right, k);
	}
    
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int k = 0;
        vector<int> v;
        DFS(root, k, v);
        int sum = 0;
        for(int i=0; i<v.size(); i++) sum+= v[i];
        return sum;
        
    }
    void DFS(TreeNode* root, int k, vector<int> &v){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            v.push_back(k*10 + root->val);
        }
        DFS(root->left, k*10+root->val, v);
        DFS(root->right, k*10+root->val, v);
    }
};
