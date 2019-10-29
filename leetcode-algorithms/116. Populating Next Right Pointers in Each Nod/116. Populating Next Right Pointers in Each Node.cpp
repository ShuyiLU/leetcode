#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
        	int size = q.size();
        	Node* tmp = q.front();
        	q.pop();
        	size--;
        	while(size>=0){
        		if(tmp->left != NULL) q.push(tmp->left);
        		if(tmp->right != NULL) q.push(tmp->right);
        		if(size == 0) tmp->next = NULL;
        		else{
        			Node* r = q.front();
        			tmp->next = r;
        			q.pop();
        			tmp = r;
				}
				size--;
			}
		}
		return root;
    }
}; 

class Solution {
public:
    Node* connect(Node* root) {
        DFS(root);
        return root;
    }
    void DFS(Node* root){
    	if(root == NULL) return;
    	if(root->left != NULL) root->left->next = root->right;
    	if(root->right != NULL) {
			if(root->next == NULL) root->right->next = NULL;
			else root->right->next = root->next->left;
		}
		DFS(root->left);
		DFS(root->right);
	}
    
};
/*
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        if(root->left == NULL){
        	root->next = NULL;
        	return root;
		}
		Node* node = root;
		while(root != NULL){
			root->left->next = root->right;
			if(root->next == NULL) root->right->next = NULL;
			else root->right->next = root->next->left;
			root = root->next
		}
		node->left = connect(node->left);
		return node;
    }
};
*/
