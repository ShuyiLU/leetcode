#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int> > verticalOrder(TreeNode* root) {
        if(root == NULL) return vector<vector<int> >  {};
        map<TreeNode*, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        set<int> s;
        mp[root] = 0;
        s.insert(0);
        while(!q.empty()){
        	TreeNode* tmp = q.front();
        	q.pop();
        	if(tmp->left != NULL){
        		q.push(tmp->left);
        		mp[tmp->left] = mp[tmp] - 1;
        		s.insert(mp[tmp->left]);
			}
			
			if(tmp->right != NULL){
				q.push(tmp->right);
				mp[tmp->right] = mp[tmp] + 1;
				s.insert(mp[tmp->right]);
			}
		}
		
		set<int> :: iterator it1;
		map<TreeNode*, int> :: iterator it2;
		vector<vector<int> > res;
		int count = -1;
		for(it1 = s.begin(); it1!=s.end(); it1++){
			res.push_back(vector<int>{});
			count++;
			for(it2 = mp.begin(); it2!= mp.end(); it2++){
				if((*it2).second == *it1) res[count].push_back((*it2).first->val);
			}
		}	
		return res;	
    }
};
