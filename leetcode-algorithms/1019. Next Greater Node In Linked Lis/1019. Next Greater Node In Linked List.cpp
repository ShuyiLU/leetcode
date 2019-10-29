#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        ListNode* p = head;
        while(p != NULL){
        	v.push_back(p->val);
        	p = p->next;	
		}
		vector<int> ans(v.size(), 0);
		stack<int> s;
		for(int i=v.size()-1; i>=0; i--){
			while( !s.empty() && s.top() <= v[i]){
				s.pop();
			}
			if(s.empty()) ans[i] = 0;
			else ans[i] = s.top();
			s.push(v[i]);
		}
		return ans;
    }
};
