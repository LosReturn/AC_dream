/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) { //BFS
            int lnum=q.size();
            int tx=-1, ty=-1; // 记录x和y的父结点，只要能区分二者父结点是否相同即可
            for (int i=0; i < lnum; ++ i) { // 当前层
                TreeNode *node = q.front(); q.pop();
                if (node->left) {
                    if (node->left->val == x) tx = i;
                    else if (node->left->val == y) ty = i;
                    q.push(node->left);
                }
                if (node->right) {
                    if (node->right->val == x) tx = i;
                    else if (node->right->val == y) ty = i;
                    q.push(node->right);
                }
                if (tx != -1 && tx == ty) return false; // 同一层，且同一个父结点
                if (tx != -1 && ty != -1 && tx != ty) return true; // 同一层，不同父结点
            }
        }
        return false;
    }
};
// @lc code=end

