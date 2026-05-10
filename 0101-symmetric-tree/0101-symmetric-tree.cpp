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

    bool check(TreeNode* a, TreeNode* b) {

        // cả hai null
        if (!a && !b) return true;

        // một null
        if (!a || !b) return false;

        // khác giá trị
        if (a->val != b->val) return false;

        // kiểm tra đối xứng
        return check(a->left, b->right) &&
               check(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return check(root->left, root->right);
    }
};