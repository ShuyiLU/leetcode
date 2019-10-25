#include<iostream>
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
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) return 0;
        
        //go through root
        int incre = findPath(root->left, root->val, 1) + 1 + findPath(root->right, root->val, -1); //从左到root递减， root到右递减 
        int decre = findPath(root->left, root->val, -1) + 1 + findPath(root->right, root->val, 1); //从左到root递增， root到右递增 
        int goRoot = max(incre, decre);
        //not go through root;
        int noRoot = max(longestConsecutive(root->left), longestConsecutive(root->right)) ;
        int res = max(noRoot, goRoot);
    }
    
    int findPath(TreeNode* root, int pre, int diff){
    	if(root == NULL) return 0;
    	if(root->val == pre + diff){
    		int left = findPath(root->left, root->val, diff);
    		int right = findPath(root->right, root->val, diff);
    		return max(left, right) + 1;
		}
		else{
			return 0;
		}
	}
    
};
