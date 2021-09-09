/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n);
        if(obstacleGrid[0][0])
            return 0;
        dp[0] = 1;
        for(int i =0; i<m; i++)
        {
            for(int j = 0; j< n; j++)
            {
                if(obstacleGrid[i][j])
                {
                    dp[j] = 0;
                    continue;
                }

                if(j>0 && !obstacleGrid[i][j-1])
                    dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

