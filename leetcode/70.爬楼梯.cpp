/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int ret[2] = {1,1};
        for(int i = 1; i < n; i++)
            ret[i%2] = ret[0] + ret[1];
        return ret[(n-1)%2];
    }
};
// @lc code=end

