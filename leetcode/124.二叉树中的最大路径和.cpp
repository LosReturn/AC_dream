/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
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
    int ret = INT_MIN;
public:
    int dfs(TreeNode* root)
    {
        
        if(root == nullptr)
        {
            return 0;
        }

        int l_val = max(dfs(root->left), 0);
        int r_val = max(dfs(root->right), 0);
        ret = max(ret,  l_val + root->val + r_val);
        return root->val + max(l_val, r_val);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ret;
    }
};
// @lc code=end

