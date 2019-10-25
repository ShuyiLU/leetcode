#include<iostream>
#include<stack>
#include<set>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
/* 
class Solution {
public:
    void reorderList(ListNode* head) {
    	if(head == NULL) return;
        stack<ListNode*> st;
        int len=0;
        ListNode* tmp1 = new ListNode(0);
        tmp1 = head;
        //cout << head->val << endl;
        while(tmp1!=NULL){
        	st.push(tmp1);
        	tmp1 = tmp1->next;
        	len++;
		}
		delete tmp1;
		
		int k = len/2;
		if(len%2 == 0) k=k-1;
		int i=0;
        ListNode* tmp = new ListNode(0);
        tmp = head;
		while(i<k && tmp!=NULL&& head != NULL && head->next != NULL){
			i++;
			tmp = head->next;
			head->next = st.top();
			st.pop();
			head = head->next;
			head->next = tmp;
			head = head->next;
		}
		if(len%2 == 0 &&head != NULL) head->next = st.top();
		delete tmp;
		
    }
};
*/

class Solution {
public:
    void reorderList(ListNode* head) {
       	if(head == NULL) return;
		vector<ListNode*> v;
		ListNode* tmp1 = new ListNode(0);
        tmp1 = head;
        while(tmp1!=NULL){
        	v.push_back(tmp1);
        	tmp1 = tmp1->next;
		}
		
		int len = v.size();
		
		int i=0, j=len-1;
		ListNode* tmp = new ListNode(0);
        tmp = head;
		while(i<len && head!=NULL && head->next!=NULL){
			
			if(i%2 == 0){
				tmp = head->next;
				head->next = v[j];
				v[j]->next = NULL;
				j--;
				i++;
				head = head->next;
			}	
			else if(i%2 == 1){
				head->next = tmp;
				tmp->next = NULL;
				i++;
				head = head->next;
			}	
		}		
		
    }
};
