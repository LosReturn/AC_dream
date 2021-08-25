/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        int t[3] = {0,1,1};

        for(int i = 3; i < n+1; i++)
        {
            t[i%3] = t[0]+t[1]+t[2];
        }

        return t[n%3];
    }
};
// @lc code=end

