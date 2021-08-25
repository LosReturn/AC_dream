/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

#include<string>

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        
        int n = s.size();
        int step = 2*k;
        for(int i=0; i<n; i+=step)
        {
            std::reverse(s.begin() +i, s.begin()+min(i+k, n));
        }

        return s;
    }
};
// @lc code=end

