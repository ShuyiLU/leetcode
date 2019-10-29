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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;
        int len=0;
        ListNode *p=head, *la=NULL;
        ListNode *h1=NULL, *h2=NULL;
        ListNode * nhd=NULL;
        while (p) {
            len++; p=p->next;
        }
        p=head;
        for (int i=len; i; i--) {
            if (i==len%k) {
                if (len%k!=0) break;
            }
            ListNode* nxt=p->next;
            if ((len-i)%k==0){
                h1=h2, h2=p;
                p->next=NULL;
            }
            else p->next=la;
            if ((len-i)%k==(k-1)) {
                if (h1) h1->next=p;
                if (!h1) nhd=p;
            }
            la=p; p=nxt;
        }
        if (h2) h2->next=p;
        if (!nhd) nhd=head;
        return nhd;
    }
};
