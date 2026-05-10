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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Tạo một nút giả (dummy) để làm điểm tựa bắt đầu danh sách kết quả
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        // Lặp khi còn phần tử ở l1, l2 hoặc còn biến nhớ
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Lấy giá trị, nếu danh sách đã hết thì mặc định là 0
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = carry + x + y;
            carry = sum / 10; // Tính số nhớ cho hàng tiếp theo
            
            // Tạo nút mới với chữ số hàng đơn vị
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Di chuyển tới nút tiếp theo của l1 và l2 nếu có
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead; // Giải phóng bộ nhớ nút giả
        return result;
    }
};