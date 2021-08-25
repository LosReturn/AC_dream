/*
 * @lc app=leetcode.cn id=446 lang=cpp
 *
 * [446] 等差数列划分 II - 子序列
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        vector<unordered_map<long,int>> dp(n);

        if( n < 3)
            return 0;

        int ret = 0;

        for(int i = 1; i < n; i++)
            for( int j = 0; j <i; j++)
            {
                long delta = (long)nums[i] - (long)nums[j];
                ++dp[i][delta];

                if( dp[j].count(delta))
                {
                    ret += dp[j][delta];
                    dp[i][delta] += dp[j][delta];
                }

            }
        return ret;
    }
};
// @lc code=end

