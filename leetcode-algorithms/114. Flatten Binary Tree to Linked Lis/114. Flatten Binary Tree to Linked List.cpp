#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode{
	int val;
	ListNode * next;
	ListNode() : {}
	ListNode(int a): val(a), next(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
       if(root == NULL) return;
       if(root->left != NULL) flatten(root->left);
       if(root->right != NULL) flatten(root->right);
       TreeNode* temp = root->right;
       root->right = root->left;
       root->left = NULL;
       while(root->right != NULL) root = root->right; //original left has subtree
       root->right = temp;
    }
       
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* cur = root;
        while(cur != NULL){
        	if(cur->left != NULL){
        	    TreeNode* tem = cur->left;
       			while(tem->right != NULL) tem = tem->right;
       			tem->right = cur->right;
       			cur->right = cur->left;
       			cur->left = NULL;	
			}
			cur = cur->right; // original cur->left, check his left subtree
	   }
	   
    }
       
};
