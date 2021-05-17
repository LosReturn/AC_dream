/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    void dfs(const TreeNode* node,int& prev, int& mins)
    {
       if(node == nullptr)
            return;
        dfs(node->left, prev, mins);
        if(prev != -1)
            mins = min(mins,node ->val - prev);
        prev = node->val;
        dfs(node->right, prev, mins);
    }

    int minDiffInBST(TreeNode* root) {
        int ret = 0x3f3f3f, prev = -1;
        dfs(root, prev, ret);
        return ret;
    }

    
};
// @lc code=end

