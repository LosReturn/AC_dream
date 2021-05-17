/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:

    int robDp(vector<int>& nums, int start, int end)
    {
        int dp[2]={0};

        for(int i = start; i < end; i++)
        {
            int temp = dp[0];
            dp[0] = max(dp[1] + nums[i], dp[0]);
            dp[1] = temp; 
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);
        
        return max(robDp(nums, 0, n-1), robDp(nums,1,n));

    }
};
// @lc code=end

