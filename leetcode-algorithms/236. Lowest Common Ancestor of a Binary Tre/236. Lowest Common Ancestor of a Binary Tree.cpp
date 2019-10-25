#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*

class Solution {
private:
	map<TreeNode*, TreeNode*> mp;	
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pr;
        vector<TreeNode*> qr;
        if(root == NULL) return NULL;
        if(p == NULL && q != NULL) return p;
        if(q == NULL && p != NULL) return q;
        if(p == NULL && q == NULL) return NULL;
        
        traverse(root);
        
       pr.push_back(p);
       qr.push_back(q);
        while(mp[p] != NULL){
        	pr.push_back(mp[p]);
        	p = mp[p];
		}
		
		while(mp[q] != NULL){
        	qr.push_back(mp[q]);
        	q = mp[q];
		}
		
		TreeNode* re = NULL;
		
		for(int i=0; i<pr.size(); i++) cout << pr[i]->val << " ";
		cout << endl;
		
		for(int i=0; i<qr.size(); i++) cout << qr[i]->val << " ";
		cout << endl;
		
		for(int i=0; i<pr.size(); i++){
			for(int j=0; j<qr.size(); j++){
				if(pr[i] == qr[j]) {
					re = pr[i];
					//break;
					return re;
					
				}
			}
		}
        
       return re;
        
    }
    
    void traverse(TreeNode* root){
    	queue<TreeNode*> q;
    	q.push(root);
    	mp[root] = NULL;
    	while(!q.empty()){
    		if(q.front()->left != NULL){
    			mp[q.front()->left] = q.front();
    			q.push(q.front()->left);
			}
			
			if(q.front()->right != NULL){
    			mp[q.front()->right] = q.front();
    			q.push(q.front()->right);
			}
			
			q.pop();			
		}
	}
    
    
};

*/

class Solution {
public:
	int getAnc(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &res){  //找到p返回1， 找到q返回2， 同时找到p q返回3 
		if(root == NULL || res!= NULL) return 0;
		
		int l = getAnc(root->left, p, q, res); //在子树同时找到p q
		if(l == 3) return 3;
		
		int r = getAnc(root->right, p, q, res); //在子树同时找到p q
		if(r == 3) return 3;
		
		if((l== 1 && r==2) || (l==2 && r==1)){
			res = root;  //左右子树各找到p q，当前节点是公共节点 
			return 3;
		}
		
		if((root == p && (l == 2 || r==2)) || (root == q && (l ==1 || r==1))){
			res = root;  //当前为其中一个节点 并且在子树找到另一个节点 
			return 3;
		}
		
		if(root == p || (l==1 || r==1)) return 1;
		else if(root == q || (l == 2 || r==2)) return 2;
		else return 0;
		
		
	}
	
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	TreeNode* res = NULL;
        getAnc(root, p, q, res);
        return res;
    }
};
