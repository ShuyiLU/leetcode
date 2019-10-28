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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p=head, *l=NULL, *r=NULL, *la=NULL;
        ListNode *sta=NULL, *end=NULL;
        for (int i=0; i<n; i++) {
            if (i==m-1) {
                l=la; sta=p;
            }
            ListNode *nxt=p->next;
            if (i>=m-1&&i<=n-1) {
                p->next=la;
            }
            if (i==n-1) {
                end=p; r=nxt;
            }
            la=p; p=nxt;
        }
        if (l) l->next=end;
        sta->next=r;
        if (l) return head;
        else return la;
    }
};
