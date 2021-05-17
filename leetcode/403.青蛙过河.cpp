/*
 * @lc app=leetcode.cn id=403 lang=cpp
 *
 * [403] 青蛙过河
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {

        if(stones[1] != 1)
            return false;

        int n = stones.size();
        vector< vector<int> > dp(n,vector<int>(n));

        for(int i = 1; i< n;i++)
            if(stones[i] - stones[i-1] > i)
                return false;

        dp[0][0] = 1;
        int distance;
        for(int i = 1; i < n; i++)
            for(int j = i-1; j >= 0; j--)
            {
                distance = stones[i] - stones[j];
                if(distance < j+1)
                    dp[i][distance] = dp[j][distance] || dp[j][distance-1] || dp[j][distance+1];
                if(i == n-1 && dp[i][distance])
                    return true;
            }
            
        return false;
    }
};
// @lc code=end

