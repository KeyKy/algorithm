// Merge Two Sorted Lists.

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
        ListNode *p = l1;
        ListNode *q = l2;
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        ListNode *pHead = new ListNode(0);
        pHead->next = l1;
        
        ListNode *p1 = pHead;
        ListNode *p2 = l1;
        
        while (q != NULL) {
            while(p2 != NULL && p2->val < q->val) {
                p1 = p1->next;
                p2 = p2->next;
            }
            
            ListNode *t = q;
            q = q->next;
            t->next = p1->next;
            p1->next = t;
            p1 = p1->next;
        }
        return pHead->next;
    }
};
