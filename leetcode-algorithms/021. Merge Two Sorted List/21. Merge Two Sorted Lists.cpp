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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans=NULL, *p=l1, *q=l2, *hd=NULL;
        for(;p||q;) {
            bool fst;
            if (!q) fst=true;
            else if (!p) fst=false;
            else if (p->val<q->val) fst=true;
            else fst=false;
            if (!ans) {
                if (fst) {ans=p; p=p->next;}
                else {ans=q; q=q->next;}
                hd=ans;
            }
            else {
                if (fst) {ans->next=p; p=p->next;}
                else {ans->next=q; q=q->next;}
                ans=ans->next;
            }
        }
        return hd;
    }
};
