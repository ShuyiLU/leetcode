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
	TreeNode* BST(vector<int>& nums, int l, int r){
		TreeNode* root;
		if(l > r) root = NULL;
		else if(l == r){
			root = new TreeNode(nums[l]);
		}
		else{
			root = new TreeNode(nums[l + (r-l)/2]);
			root -> left = BST(nums, l, l + (r-l)/2-1);
			root -> right = BST(nums, l + (r-l)/2+1, r);
		}
		return root;
	}
	
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	TreeNode* root;
        int n = nums.size();
        if(n == 1) {
        	root = new TreeNode(nums[0]);
		}
		else{
			root = BST(nums, 0, n-1);
		}
		return root;
    }
};

/*
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	
        int n = nums.size();
        if(n == 1) {
        	TreeNode* T = new TreeNode(nums[0]);
        	return T;
		}
		else{
			vector<int> l;
			vector<int> r;
			for(int i=0; i<n/2; i++){
				l.push_back(nums[i]);
			}
			for(int i=n/2+1; i<n; i++){
				r.push_back(nums[i]); 
			}
			TreeNode* root = new TreeNode(nums[n/2]);
			root -> left = sortedArrayToBST(l);
			root -> right = sortedArrayToBST(r);
			return root;
		}
    }
};
*/
