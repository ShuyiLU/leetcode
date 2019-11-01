class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL) return head;
		ListNode* h = new ListNode(0);
		h->next = head;
		ListNode* cur = h;
		ListNode* np = h;
		ListNode* mp = h;
		while(m>0){
			mp = mp->next;
			m--;
		}
		
		while(n>0){
			np = np->next;
			n--;
		}
		
		while(cur != NULL && cur->next != mp) cur = cur->next;
		
		ListNode* after = new ListNode(0);
		while( cur != NULL && cur->next != np ){
			after = mp->next;
			mp->next = np->next;
            np->next = mp;
			cur->next = after;
			mp = after;
			
		}
		return h->next;
    }
};