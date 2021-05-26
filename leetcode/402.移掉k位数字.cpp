/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

#include <stack>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> mstack;

        for(int i = 0; i < num.size(); i++)
        {
            while( mstack.size() > 0 && mstack.top() > num[i] && k)
            {
                k--;
                mstack.pop();
            }
            mstack.push(num[i]);
        }

        while(k>0)
        {
            mstack.pop();
            k--;
        }

        string ret = "";
        while(!mstack.empty())
        {
            ret+=mstack.top();
            mstack.pop();
        }

        reverse(ret.begin(), ret.end());
        int zero = 0;
        
        while(ret[zero] == '0') zero++;
        ret = ret.substr(zero);
        return ret == "" ? "0": ret;
    }

    // we can use vector instead of stack
    string removeKdigits2(string num, int k) {
        vector<char> mstack;

        for(int i = 0; i < num.size(); i++)
        {
            while( mstack.size() > 0 && mstack.back() > num[i] && k)
            {
                k--;
                mstack.pop_back();
            }
            mstack.push_back(num[i]);
        }

        while(k>0)
        {
            mstack.pop_back();
            k--;
        }

        string ret = "";
        int zero = 0;
        while(ret[zero] == '0') zero++;

        for(int i = zero; i < mstack.size(); i++)
            ret += mstack[i];
        
        return ret == "" ? "0": ret;
    }
};
// @lc code=end

