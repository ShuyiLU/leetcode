#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
        	fast = fast->next->next;
        	slow = slow->next;
		}
		ListNode* rHead = slow->next;
		slow -> next = NULL;
		ListNode* l = sortList(head);
		ListNode* r = sortList(rHead);
		return merge(l, r); 
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
    	ListNode* head = new ListNode(0);
    	ListNode* p = head;
    	while(l1 != NULL && l2 != NULL){
    		if(l1->val < l2->val){
    			p->next = l1;
    			p = p->next;
    			l1 = l1->next;
			}
			else{
				p->next = l2;
				p = p->next;
				l2 = l2->next;
			}
		}
		while(l1 != NULL){
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		} 
		while(l2 != NULL){
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		} 
		return head->next;
	}
    
}; 
