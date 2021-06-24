/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include <stdint.h>
// @lc code=start
class Solution {
public:
    int hammingWeight_fbsd2(uint32_t n) {
        n -= ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n + (n >> 4)) & 0x0F0F0F0F;
        n = (n * 0x01010101) >> 24;
        return n;
    }

    int hammingWeight_fbsd1(uint32_t n) {
        n = (n & 0x55555555) + ((n & 0xaaaaaaaa) >> 1);
        n = (n & 0x33333333) + ((n & 0xcccccccc) >> 2);
        n = (n & 0x0f0f0f0f) + ((n & 0xf0f0f0f0) >> 4);
        n = (n & 0x00ff00ff) + ((n & 0xff00ff00) >> 8);
        n = (n & 0x0000ffff) + ((n & 0xffff0000) >> 16);
        return n;
    }

    int hammingWeight_Java(uint32_t n){
        n = n- ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n + (n >> 4)) & 0x0f0f0f0f;
        n = n+ (n >> 8);
        n = n+ (n >> 16);
        return n & 0x3f;
    }

    int hammingWeight(uint32_t n)
    {
        int __cnt__ = 0;
        while(n)
        {
            n &= (n-1);
            __cnt__++;
        }
        return __cnt__;
    }
};
// @lc code=end

