/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* revList(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* revHead = revList(head);
        ListNode* mover = revHead;
        int i = 1;
        if (n == 1) {
            revHead = revHead->next;
            return revList(revHead);
        }
        while (i < n - 1) {
            mover = mover->next;
            ++i;
        }
        mover->next = mover->next->next;
        return revList(revHead);
    }
};