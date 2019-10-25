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
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*> {};
        return DFS(1, n);
	}
	vector<TreeNode*> DFS(int i, int j){
		vector<TreeNode*> res;
		if(i > j) res.push_back(NULL);
		else if(i == j) res.push_back(new TreeNode(i));
		else {
			for(int k=i; k<=j; k++){
				vector<TreeNode*> l = DFS(i, k-1);
				vector<TreeNode*> r = DFS(k+1, j);
				for(int p=0; p<l.size(); p++){
					for(int q=0; q<r.size(); q++){
						TreeNode* h = new TreeNode(k);
						h->left = l[p];
						h->right = r[q];
						res.push_back(h);
					}
				}
			}
		}
		return res;
	}
};
