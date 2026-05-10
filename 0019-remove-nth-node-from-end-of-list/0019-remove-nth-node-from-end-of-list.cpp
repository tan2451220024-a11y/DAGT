/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Tạo một node giả (dummy) trỏ đến đầu danh sách
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Di chuyển con trỏ 'first' đi trước n + 1 bước
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        // Di chuyển cả hai con trỏ cho đến khi 'first' chạm cuối danh sách
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // 'second' bây giờ đang đứng ngay trước node cần xóa
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        
        // Giải phóng bộ nhớ của node bị xóa
        delete nodeToDelete;

        // Trả về đầu danh sách mới
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
