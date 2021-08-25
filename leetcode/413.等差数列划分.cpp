/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 3)
            return 0;
        
        int delta = nums[1] - nums[0], step = 0;
        int ret = 0;

        for( int i =2; i < n; i++)
        {
            int temp = nums[i] - nums[i-1];
            if( temp == delta)
            {
                ++step;
            }
            else{
                step = 0;
                delta = temp;
            }

            ret += step;
        }
        return ret;
    }
};
// @lc code=end

