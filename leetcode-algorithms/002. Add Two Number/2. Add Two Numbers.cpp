#include<iostream>

using namespace std; 




 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        int add = 0;
        while(l1 || l2 || add){
        	int sum = 0;
        	if(l1){
        		sum = sum + l1->val;
        		l1 = l1->next;
			}
			if(l2){
				sum = sum + l2->val;
				l2 = l2->next;
			} 
			sum = sum + add;
			tmp->next = new ListNode(sum%10);
			tmp = tmp->next;
			add = sum/10;			
		}
		ListNode* ret = head->next;
		delete head;
		return ret;
    }
};
