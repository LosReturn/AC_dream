/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for( auto num: nums)
            sum+=num;

        if(sum < target)
            return 0;

        sum+=target;

        if( sum & 1 )
            return false;

        int positive = sum/2 ;
        vector<int> dp( positive + 1, 0);
        dp[0] = 1;

        for( int i = 0; i < nums.size(); i++)
        {
            for(int j = positive; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];
        }      
        return dp[positive];
    }
};
// @lc code=end

