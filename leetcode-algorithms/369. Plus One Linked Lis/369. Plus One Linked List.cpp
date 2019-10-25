/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if(jinWei(head)){
        	ListNode* newHead = new ListNode(1);
        	newHead->next = head;
        	return newHead;
		}
		return head;
    }

	int jinWei(ListNode* head){
		if (head == NULL) return 1;  //在linklist末尾加上1，即原末位+1是由末位后一位进位得到 
		if(jinWei(head->next)){ //如果当前有进位，加进位 
			if(head->val < 9){
				head->val = head->val+1;
				return 0;
			} 
			else{
				head->val = 0;
				return 1;
			}
		}
		return 0;
	}
};
