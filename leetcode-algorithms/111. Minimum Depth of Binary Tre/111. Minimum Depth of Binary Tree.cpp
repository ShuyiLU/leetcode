#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
private:
	//vector<int> depth;
	int min = -1;
	
	
public:
    int minDepth(TreeNode* root) {
    	if(root == NULL) return 0;
        DFS(root, 1);
        //sort(depth.begin(), depth.end());
        return min;
    }
    
    void DFS(TreeNode* root, int len){
    	
		if(root -> left == NULL && root->right == NULL){
			//depth.push_back(len);
			if(min == -1) min = len;
			else if(len < min) min = len;
		}
		
		if(root->left != NULL){
			//len++;
			DFS(root->left, len+1);
		}
		
		if(root->right != NULL){
			//len++;
			DFS(root->right, len+1);
		}
		
	}
};

int main(){
}
