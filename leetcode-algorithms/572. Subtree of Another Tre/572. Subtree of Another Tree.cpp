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
private:
	vector<int> re;
	vector<int> v1;
	vector<int> v2;
	int flag;
public:
    
    vector<int> In(TreeNode * root){
    	//vector<int> re;
    	//while(!re.empty()) re.clear();
    	if(root != NULL){
    		re.push_back(root->val);
    		In(root->left);
    		In(root->right);
		}
		return re;
	}
    
    
    void Inorder(TreeNode* s, TreeNode* t){
    	//flag = 0;
        if( s!= NULL){
            if(s->val == t->val){
            	v1.clear();
            	v2.clear();
                v1 = In(s);
                v2 = In(t);
                if(v1.size() == v2.size()){
                	int c = 0;
                	for(int i=0; i<v2.size(); i++){
                		if(v1[i] == v2[i]) {
                			continue;
						}
						else{
							c = 1;
							break;
						}
					}    
					if(c == 0){
						flag = 0;
						return;
					}            
				}				
				
            }
            Inorder(s->left,t);
            Inorder(s->right,t);
        }
    }
    
    
    bool isSubtree(TreeNode* s, TreeNode* t) {      
        if(flag == 0) return true;
        else return false;
    }
};


class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL && t == NULL) return true;
        else if(s == NULL || t == NULL) return false;
        else if(same(s,t)) return true;
        else{
        	return isSubtree(s->left, t) ||	isSubtree(s->right, t);
		}
        
    }
    
    bool same(TreeNode* s, TreeNode* t){
    	if(s == NULL && t == NULL) return true;
        else if(s == NULL || t == NULL) return false;
        else if(s->val != t->val) return false;
        else{
        	return same(s->left, t->left) && same(s->right, t->right);
		}
        
	}
};
