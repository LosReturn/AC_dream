/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int num: nums)
            ret ^= num;
        int div = 1;
        while(div & ~ret)
            div <<= 1;
        int a=0, b= 0;
        for(int num: nums)
        {
            if(div&num)
                a^=num;
            else
                b^=num;
        }
        return {a,b};
    }
};
// @lc code=end

