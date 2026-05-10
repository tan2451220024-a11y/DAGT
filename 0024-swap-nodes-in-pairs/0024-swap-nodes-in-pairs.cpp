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
    ListNode* swapPairs(ListNode* head) {
         // Node giả
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // còn đủ 2 node để swap
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Hoán đổi
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Di chuyển sang cặp tiếp theo
            prev = first;
        }

        return dummy.next;
    }
};