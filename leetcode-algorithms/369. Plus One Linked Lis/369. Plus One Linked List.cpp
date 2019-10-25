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
		if (head == NULL) return 1;  //��linklistĩβ����1����ԭĩλ+1����ĩλ��һλ��λ�õ� 
		if(jinWei(head->next)){ //�����ǰ�н�λ���ӽ�λ 
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
