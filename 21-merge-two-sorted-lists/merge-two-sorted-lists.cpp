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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) {
            return (!list1) ? list2 : list1;
        }
        ListNode* merged;
        if (list1->val <= list2->val) {
            merged = list1;
            list1 = list1->next;
        } else {
            merged = list2;
            list2 = list2->next;
        }
        ListNode * head = merged;
        while (list1 && list2 ) {
            if (list1->val <= list2->val) {
                merged->next = list1;
                list1 = list1->next;
            } else {
                merged->next = list2;
                list2 = list2->next;
            }
            merged = merged->next;
        }
        while (list1) {
            merged->next = list1;
            list1 = list1->next;
            merged = merged->next;
        }
        while (list2) {
            merged->next = list2;
            list2 = list2->next;
            merged = merged->next;
        }
        return head;
    }
};