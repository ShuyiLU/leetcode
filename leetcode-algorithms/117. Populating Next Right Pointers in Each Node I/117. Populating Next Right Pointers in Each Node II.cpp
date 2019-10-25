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
        DFS(root);
        return root;
    }
    void DFS(Node* root){
    	if(root == NULL) return;
    	if(root->left != NULL) {
    		if(root->right != NULL) root->left->next = root->right;
    		else{
    			Node* q = root->next;
    			root->left->next = NULL;
    			while(q != NULL){
    				if(q->left != NULL){
    					root->left->next = q->left;
    					break;
					} 
					else if(q->right != NULL){
						root->left->next = q->right;
						break;
					}
					else q = q->next;
				}				
			}		
		}
    	if(root->right != NULL) {
    		Node* q = root->next;
    		root->right->next = NULL;
    		while(q != NULL){
    			if(q->left != NULL){
    				root->right->next = q->left;
    				break;
				} 
				else if(q->right != NULL){
					root->right->next = q->right;
					break;
				}
				else q = q->next;
			}
		}
		DFS(root->right);
		DFS(root->left);
	}
    
};



class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> l;
        dfs(root, 0, l);
        return root;
    }
    void dfs(Node* root, int level, vector<Node*> l){
    	if(root == NULL) return;
    	if(l.size() <= level) l.push_back(root);
    	else{
    		Node* n = l[level];
    		n->next = root;
    		l[level] = root;
		}
		
		dfs(root->left, level+1, l);
		dfs(root->right, level+1, l);
		
	}
};
