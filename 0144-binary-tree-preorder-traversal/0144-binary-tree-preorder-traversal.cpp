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
    vector<int> result;

    void dfs(TreeNode* root) {
        if (root == nullptr) return;

        result.push_back(root->val); // Root
        dfs(root->left);             // Left
        dfs(root->right);            // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
};