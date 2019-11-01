/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        bool None = false;
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0; i<size; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp == NULL){
                    None = true;
                    continue;
                }
                
                if(None == true){
                    return false;
                }
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return true;
    }
};
