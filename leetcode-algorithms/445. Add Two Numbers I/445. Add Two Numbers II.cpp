#include<iostream>
#include<stack>
using namespace std;
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int add = 0;
        if(l1 == NULL && l2 == NULL) return NULL;
        stack<int> s1;
        stack<int> s2;
        stack<int> s3; 
        
        while(l1) {
        	s1.push(l1->val);
        	l1 = l1->next;
		}
		
		while(l2) {
			s2.push(l2->val);
			l2 = l2 -> next;
		}
        
        while(!s1.empty() && !s2.empty()){
        	sum = s1.top() + s2.top() + add;
        	s3.push(sum%10);
        	add = sum/10;
        	s1.pop();
        	s2.pop();
		}
		
		if(!s1.empty()){
			while(!s1.empty()){
				sum = s1.top() + add;
				s3.push(sum%10);
				add = sum/10;
				s1.pop();
			}
		}
		
		if(!s2.empty()){
			while(!s2.empty()){
				sum = s2.top() + add;
				s3.push(sum%10);
				add = sum/10;
				s2.pop();
			}
		}
		
		if(add > 0) s3.push(add);
		
		ListNode* head = new ListNode(0);
		ListNode* tmp = head;
		while(!s3.empty()){
			tmp->next = new ListNode(s3.top());
			tmp = tmp->next;
			s3.pop(); 
		}
		ListNode* res = head->next;
		delete head;
		return res;     
        
    }
};
