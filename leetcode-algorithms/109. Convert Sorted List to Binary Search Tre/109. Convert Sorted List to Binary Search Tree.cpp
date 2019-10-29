#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
public:
	vector<int> v;
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
		while(head != NULL){
			v.push_back(head->val);
			head = head->next;
		}
		int n = v.size();
		int l=0, r=n-1;
		return newBST(v, l, r);			
    }
    
    TreeNode* newBST(vector<int> v, int l, int r){
    	if(l>r) return NULL;
		int mid = (l+r)/2;
    	TreeNode* root = new TreeNode(v[mid]);
    	root->left = newBST(v, l, mid-1);
    	root->right = newBST(v, mid+1, r);
    	return root;
	}
};
*/



class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if(head == NULL) return NULL;
    	if(head->next == NULL) return new TreeNode(head->val);
    	ListNode* t = head;
		while(t->next != NULL) t = t->next;
		return newBST(head, t);	
    }
    
    TreeNode* newBST(ListNode* head, ListNode* tail){
    	ListNode* mid = NULL;
    	ListNode* slow = head;
		ListNode* fast = head;
        while( fast != NULL && fast->next != NULL){
        	slow = slow->next;
        	fast = fast->next->next;
		}
		 mid = slow;
		ListNode* rightHead = mid->next;
		TreeNode* root = new TreeNode(mid->val);
		if(mid != head)root->left = newBST(head, mid);
		if(mid->next != NULL)root->right = newBST(rightHead, tail);
		return root;
	}
};

