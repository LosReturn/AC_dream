/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int _xor = x^y;
        int ret = 0;
        while(_xor!=0)
        {
            _xor&=(_xor-1);
            ret++;
        }
        return ret;
    }
};
// @lc code=end

