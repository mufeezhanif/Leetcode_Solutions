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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> s1, s2;
        ListNode* mover = headA;
        while (mover) {
            s1.insert(mover);
            mover = mover->next;
        }
        mover = headB;
        while (mover) {
            s2.insert(mover);
            mover = mover->next;
        }
        mover = headA;
        while (mover) {
            if (s2.count(mover)) {
                return mover;
            }
            mover = mover->next;
        }
        return nullptr;
    }
};