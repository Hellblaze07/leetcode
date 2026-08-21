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
    unordered_map<TreeNode*, int> memo;
public:
    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } 
        if (memo.count(root)) {
            return memo[root];
        }
        int robRoot = root->val;
        if (root->left) {
            robRoot += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            robRoot += rob(root->right->left) + rob(root->right->right);
        }
        int notRobRoot = rob(root->left) + rob(root->right);
        return memo[root] = max(robRoot, notRobRoot);
    }
};