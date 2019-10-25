struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        return max(max(maximumAverageSubtree(root->left), maximumAverageSubtree(root->right)), avg(root));
    }
    
    double avg(TreeNode* root){
    	if(root->left == NULL && root->right == NULL) return root->val;
    	if(root->left == NULL){
    		int cnt = count(root->right);
    		return (avg(root->right) * cnt + root->val)/(cnt+1);
		}
		if(root->right == NULL){
    		int cnt = count(root->left);
    		return (avg(root->left) * cnt + root->val)/(cnt+1);
		}
		
		int cnt1 = count(root->left), cnt2 = count(root->right);
		return(avg(root->left) * cnt1 + avg(root->right) * cnt2 + root->val) / (cnt1+cnt2+1);
    	
	}
	
	int count(TreeNode* root){
		//if(root == NULL) return 0;
		if(root->left == NULL && root->right == NULL) return 1;
		if(root->left == NULL) return count(root->right) + 1;
		if(root->right == NULL) return count(root->left) + 1;
		return count(root->left) + count(root->right) + 1;
	}
    
};
