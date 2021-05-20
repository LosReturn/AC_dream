/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <queue>
using namespace std;

class Solution {
public:
    //same 100
    bool isSymmetricTree(TreeNode* p, TreeNode* q) {
        if( !p || !q)
            return p == q;
        if(p->val != q->val)
            return false;
        return isSymmetricTree(p->left, q->right) && isSymmetricTree(p->right, q->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isSymmetricTreeForward(root->left, root->right);
    }
    //TODO iters
    bool isSymmetricTreeForward(TreeNode* p, TreeNode* q)
    {
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);

        while (!que.empty())
        {
            p = que.front();
            que.pop();
            q = que.front();
            que.pop();

            if( !p || !q)
            {
                if(p == q)
                    continue;
                return false;
            }

            if(p->val != q->val)
                return false;

            que.push(p->left);
            que.push(q->right);
            que.push(p->right);
            que.push(q->left);
            
        }
        return true;
    }

};
// @lc code=end

