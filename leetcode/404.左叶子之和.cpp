/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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

    bool isLeafNode(TreeNode* node) {
        return !node->left && !node->right;
    }

    int sumOfLeftLeaves(TreeNode* root, int ret = 0) {
        
        if(root == nullptr)
            return 0;

        if(root->left)
        {
            ret += isLeafNode(root->left) ? root->left->val : sumOfLeftLeaves( root->left    );
        }

        if(root->right && !isLeafNode(root->right))
        {
            ret += sumOfLeftLeaves(root->right);
        }

        return ret;
    }
};
// @lc code=end

