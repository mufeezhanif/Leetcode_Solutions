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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        while (head && st.count(head->val)) {
            head = head->next;
        }
        ListNode* mover = head;
        while (mover && mover->next) {
            if (st.count(mover->next->val)) {
                mover->next = mover->next->next;
                continue;
            }
            mover = mover->next;
        }
        return head;
    }
};