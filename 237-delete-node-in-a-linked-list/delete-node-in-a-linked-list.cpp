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
    void deleteNode(ListNode* node) {
        ListNode* mover = node;
        ListNode*prev = NULL;
        while (mover && mover->next) {
            mover->val = mover->next->val;
            prev = mover;
            mover = mover->next;
        }
        prev->next = nullptr;
    }
};