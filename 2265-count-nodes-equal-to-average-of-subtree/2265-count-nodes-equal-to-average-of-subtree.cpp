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
    pair<int,int> func(TreeNode* root,int &count)
    {
        int sum1=0;
        int count1=0;
        if(root->left)
        {
            auto it1=func(root->left,count);
            sum1=it1.first;
            count1=it1.second;

        }
        int sum2=0;
        int count2=0;
        if(root -> right)
        {
            auto it2=func(root -> right,count);
            sum2=it2.first;
            count2=it2.second;       
        }
        if((sum1+sum2+root->val)/(count1+count2+1) == root->val)
        count++;
        return {sum1+sum2+root->val,count1+count2+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        auto it=func(root,count);
        return count;
    }
};