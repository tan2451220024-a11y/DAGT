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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    ListNode* findMiddle(ListNode* head, ListNode* &prev) {
        ListNode* slow = head;
        ListNode* fast = head;

        prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    TreeNode* build(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* prev = nullptr;
        ListNode* mid = findMiddle(head, prev);

        // cắt list
        if (prev) prev->next = nullptr;

        TreeNode* root = new TreeNode(mid->val);

        // nếu mid == head → không có trái
        if (mid != head)
            root->left = build(head);

        root->right = build(mid->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return build(head);
    }
};