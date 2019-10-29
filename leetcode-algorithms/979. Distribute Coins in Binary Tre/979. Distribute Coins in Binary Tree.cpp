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
    	ans = abs(ans) + abs(f(root->left)) + abs(f(root->right)); // �ۼ��ƶ�Ӳ�ҵĴ���������ֵ��
		return f(root->left) + f(root->right) + root->val - 1;  // ����ÿ���ڵ��Ƴ���Ӳ�����������Ǹ������� ������Ƴ�+�ұ��Ƴ�+�����е�-1��Ҫ�� 
	}  
    
};

int main(){
}
