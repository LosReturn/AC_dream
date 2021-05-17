/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include <string>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // stack
    int longestValidParentheses(string s) {
        stack<int> m_stack;
        int n = s.size();
        vector<int> mark(n,0);
        int ret = 0;

        for(int i = 0; i < n; i++) {
            if (s[i] == '(') {
                m_stack.push(i);
            } else {
                if (m_stack.empty())
                    mark[i] = 1;
                else
                    m_stack.pop();
            }
        }

            while ( !m_stack.empty() )
            {
                mark[m_stack.top()] = 1;
                m_stack.pop();
            }

            int continuity = 0;
            for(int i=0; i < n; i++)
            {
                if(mark[i])
                {
                    ret = max(ret, continuity);
                    continuity = 0;
                    continue;
                }
                continuity++;
            }
            ret = max(ret, continuity);
            
        return ret;
    }

/*
    //this is 2-time travel
    int longestValidParentheses(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int mlength = 0;
        for(int i=0; i < n; i++)
        {
            if(s[i]=='(')
                left++;
            else
                right++;
            if(left == right)
                mlength = max(mlength, 2*right);
            if(right > left)
            {
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='(')
                left++;
            else
                right++;
            if(left == right)
                mlength = max(mlength, 2*left);
            if(left > right)
            {
                left = 0;
                right = 0;
            }
        }
        return mlength;
    }
    */
};
// @lc code=end

