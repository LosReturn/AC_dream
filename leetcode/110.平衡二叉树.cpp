/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
public:
    bool isBalanced(TreeNode* root) {
        return computeDepth(root) >= 0;
    }

    int computeDepth(TreeNode* node)
    {
        if(node == nullptr)
        {
            return 0;
        }

        int left = computeDepth(node->left);
        int right = computeDepth(node->right);

        if( abs(left - right) > 1  || left == -1 || right == -1)
            return -1;

        return max(left, right) + 1;

    }
};
// @lc code=end

