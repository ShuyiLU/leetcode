#include<iostream>
#include<queue>
#include<map>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> ans;
        if(root == NULL) return vector<int>{};		
        queue <pair<TreeNode*, int> > q;
        q.push(make_pair(root,1));
        pair<TreeNode*, int> cur;
        pair<TreeNode*, int> last(NULL,0);
        while(!q.empty()){
        	cur = q.front();
        	q.pop();
        	if(last.first != NULL && last.second != cur.second) ans.push_back(last.first->val);
        	if(cur.first->left != NULL) {
        		q.push(make_pair(cur.first->left, cur.second + 1));
        		
			}
        	if(cur.first->right != NULL){
        		q.push(make_pair(cur.first->right, cur.second + 1));
			} 
			
        	last = cur;
		}
		ans.push_back(last.first->val); 
		return ans;
	}
}; 

int main(){
	
}
