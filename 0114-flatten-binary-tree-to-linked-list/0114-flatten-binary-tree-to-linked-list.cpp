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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* leftSubtree = root->left;
        TreeNode* rightSubtree = root->right;

        // Đưa cây trái sang phải
        root->right = leftSubtree;
        root->left = nullptr;

        // Tìm cuối danh sách bên phải hiện tại
        TreeNode* current = root;

        while (current->right != nullptr) {
            current = current->right;
        }

        // Nối phần phải cũ vào cuối
        current->right = rightSubtree;
    }
};