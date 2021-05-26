/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        int tmp;
        while(b)
        {
            tmp = a^b;
            b = (unsigned)(a&b)<<1;
            a = tmp;
        }
        return a;
    }
};
// @lc code=end

