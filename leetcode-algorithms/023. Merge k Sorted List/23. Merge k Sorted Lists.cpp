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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *p=NULL, *hd=NULL;
        priority_queue<pair<int, int>> Q;
        for (int i=0; i<lists.size(); i++) if (lists[i]) Q.push(make_pair(-lists[i]->val, i));
        while (!Q.empty()) {
            pair<int, int> prr=Q.top(); Q.pop();
            int i=prr.second;
            if (!p) {
                p=lists[i]; hd=p;
            }
            else {
                p->next=lists[i]; p=p->next;
            }
            lists[i]=lists[i]->next;
            if (lists[i]) Q.push(make_pair(-lists[i]->val, i));
        }
        return hd;
    }
};
