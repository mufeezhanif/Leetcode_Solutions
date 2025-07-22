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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* mover = head;
        while (mover && mover->next) {
            if (mover->next->val == mover->val) {
                mover->next = mover->next->next;
                continue;
            }
            mover = mover->next;
        }
        return head;
    }
};