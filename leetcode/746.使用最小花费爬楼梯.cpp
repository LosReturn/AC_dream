/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    // int minCostClimbingStairs(vector<int>& cost) {
        
    //     int n = cost.size();
    //     vector<int> dp(n+1, 0);
        
    //     for(int i =2; i<=n; i++)
    //     {
    //         dp[i] = min(dp[i-1]+cost[i-1], dp[i-2] + cost[i-2]);
    //     }
    //     return dp[n];
    // }

    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int state[2] = {0};
        
        for(int i =2; i<=n; i++)
        {
            state[i%2] = min(state[(i-1)%2]+cost[i-1], state[i%2] + cost[i-2]);
        }
        return state[n%2];
    }
};
// @lc code=end

