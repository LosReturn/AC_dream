/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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

#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
/*
    void dfs(vector<int>& seq, TreeNode* root)
    {
        if( root->left == nullptr && root->right == nullptr)
        {
            seq.push_back(root->val);
            return;
        }

        if( root->left)
        {
            dfs(seq, root->left);
        }

        if(root->right)
            dfs(seq, root->right);

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;

        dfs( leaf1, root1);
        dfs(leaf2, root2);

        return leaf1 == leaf2;
    }
*/
/*
    void forward(vector<int>& seq, TreeNode* root)
    {
        stack<TreeNode*> history;

        TreeNode* curr;
        history.push(root);

        while( !history.empty())
        {
            curr = history.top();
            history.pop();
            while(curr->left || curr->right)
            {
                if(curr->left)
                {
                    if(curr->right)
                        history.push(curr->right);
                    curr = curr -> left;
                }
                else
                    curr = curr->right;
            }
            seq.push_back(curr->val);
        }

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;

        forward( leaf1, root1);
        forward(leaf2, root2);

        return leaf1 == leaf2;
    }
    */

   bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> history1;
        stack<TreeNode*> history2;
        TreeNode* curr1;
        TreeNode* curr2;
        history1.push(root1);
        history2.push(root2);

        while( !history1.empty() && !history2.empty())
        {
            curr1 = history1.top();
            history1.pop();
            curr2 = history2.top();
            history2.pop();
            while(curr1->left || curr1->right)
            {
                if(curr1->left)
                {
                    if(curr1->right)
                        history1.push(curr1->right);
                    curr1 = curr1 -> left;
                }
                else
                    curr1 = curr1->right;
            }

            while(curr2->left || curr2->right)
            {
                if(curr2->left)
                {
                    if(curr2->right)
                        history2.push(curr2->right);
                    curr2 = curr2 -> left;
                }
                else
                    curr2 = curr2->right;
            }

            if(curr1->val != curr2->val)
                return false;
        }

        return history1.empty() && history2.empty();
    }
};
// @lc code=end

