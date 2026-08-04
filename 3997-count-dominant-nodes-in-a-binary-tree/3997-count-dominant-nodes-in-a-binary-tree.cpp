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
    int dfs(TreeNode* root,int& count)
    {
        int maxi=root->val;
        if(root -> left)
        maxi=max(maxi,dfs(root->left,count));
        if(root -> right)
        maxi=max(maxi,dfs(root->right,count));
        if(maxi == root->val)
        count++;
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        int count=0;
       int m= dfs(root,count);
       return count;
    }
};