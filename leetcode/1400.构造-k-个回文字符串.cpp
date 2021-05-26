/*
 * @lc app=leetcode.cn id=1400 lang=cpp
 *
 * [1400] 构造 K 个回文字符串
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canConstruct(string s, int k) {
        bool cnt[26] = {false};

        for(auto& ch : s)
        {
            cnt[ch-'a'] = !cnt[ch-'a'];
        }

        int ret = 0;
        for(auto& isOdd : cnt)
        {
            if(isOdd)
                ret++;
        }        

        return ret <= k && k <= s.size();
    }
};
// @lc code=end

