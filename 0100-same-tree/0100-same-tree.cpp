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
    bool isSameTree(TreeNode* p, TreeNode* q) {
          if (!p && !q) return true;

        // một rỗng, một không
        if (!p || !q) return false;

        // giá trị khác nhau
        if (p->val != q->val) return false;

        // kiểm tra đệ quy trái + phải
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};