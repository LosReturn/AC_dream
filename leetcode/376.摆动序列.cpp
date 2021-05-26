/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int prev;
        if( nums.size() < 2)
            return 1;
        int pdiff = nums[1] - nums[0];
        int ret = pdiff == 0? 1: 2; 
        for( int i = 2; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i-1];
            if( diff > 0 && pdiff <= 0 || diff < 0 && pdiff >= 0)
            {
                ret++;
                pdiff = diff;   
            }
        } 
        return ret;
    }
    //TODO: DP
};
// @lc code=end

