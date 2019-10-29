#include<iostream>
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
	int ans = 0;
public:
    int distributeCoins(TreeNode* root) {
    	if(root == NULL) return 0;
        f(root);
        return ans;
    }
    
    int f(TreeNode* root){
    	if(root == NULL) return 0;
    	ans = abs(ans) + abs(f(root->left)) + abs(f(root->right)); // 累加移动硬币的次数（绝对值）
		return f(root->left) + f(root->right) + root->val - 1;  // 计算每个节点移出的硬币数（可能是负数）， 是左边移出+右边移出+本身有的-1（要求） 
	}  
    
};

int main(){
}
