/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ret = 0x3f3f3f, prev = -1;
        dfs(root, prev, ret);
        return ret;
    }
    
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

};
// @lc code=end

