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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Nếu không có cây con trái
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }

        // Nếu không có cây con phải
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }

        // Có cả hai cây con
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};