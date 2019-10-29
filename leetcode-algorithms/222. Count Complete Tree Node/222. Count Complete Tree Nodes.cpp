/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*

class Solution {
public:
    int countNodes(TreeNode* root) {
    	int count; 
        int count_l;
		int count_r;
        if(root->left == NULL) count_l = 0;
        else count_l = countNodes(root->left);
        if(root->right == NULL) count_r = 0;
        else count_l = countNodes(root->right);
        count = count_l + count_r + 1;
        return count;
    }
};
*/

/*
class Solution {
public:
    int countNodes(TreeNode* root) {
    	int count; 
        if(root == NULL) return 0;
        if(root->left != NULL && root->right != NULL ) {
        	count = countNodes(root->left) + countNodes(root->right) + 1;
		}
        else if(root->left == NULL) return 1;
        else if(root->left != NULL && root->right == NULL) count = countNodes(root->left) + 1;
        return count;
    }
};
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int getLeftHeight(TreeNode* root){
	int count = 1;
	while(root->left != NULL){
		root = root->left;
		count++;
	}
	return count;
}

int getRightHeight(TreeNode* root){
	int count = 1;
	while(root->right != NULL){
		root = root->right;
		count++;
	}
	return count;
}


 
class Solution {
public:
    int countNodes(TreeNode* root) {
    	if(root == NULL) return 0;
    	int h_l = getLeftHeight(root);
    	int h_r = getRightHeight(root);
    	if(h_l == h_r) return pow(2,h_l) - 1;
    	else{
    		return countNodes(root->left) + countNodes(root->right) + 1;
		}
    }
};

/*
class Solution {
public:
    int countNodes(TreeNode* root) {
    	if(root == NULL) return 0;
    	queue<TreeNode*>  q;
    	q.push(root);
    	int count = 0;
    	while(!q.empty()){
    		TreeNode * tmp = q.front();
    		if(tmp->left != NULL) q.push(tmp->left);
    		if(tmp->right != NULL) q.push(tmp->right);
    		q.pop();
    		count++;
		}
    	return count;
    }
};
*/


