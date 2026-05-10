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
    ListNode* rotateRight(ListNode* head, int k) {
        // Trường hợp đặc biệt: danh sách rỗng, có 1 nút hoặc k = 0
        if (!head || !head->next || k == 0) return head;

        // 1. Tính độ dài danh sách và tìm nút cuối cùng
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // 2. Tối ưu k
        k = k % length;
        if (k == 0) return head;

        // 3. Nối đuôi vào đầu để tạo vòng tròn
        tail->next = head;

        // 4. Tìm vị trí ngắt mới
        // Điểm ngắt nằm ở bước thứ (length - k)
        int stepsToNewTail = length - k;
        ListNode* newTail = tail; 
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // 5. Thiết lập head mới và ngắt vòng
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};