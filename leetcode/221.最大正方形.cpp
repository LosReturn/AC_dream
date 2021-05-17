/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        int ret = 0;
        for(int row = 0; row < matrix.size(); row++)
            for(int col = 0; col < matrix[0].size(); col++)
            {
                if(matrix[row][col] == '1')
                {
                    dp[row+1][col+1] = min(dp[row][col], min(dp[row+1][col], dp[row][col+1])) + 1;
                    ret = max(ret, dp[row+1][col+1]);
                }    
            }
        return ret*ret;
    }
};
// @lc code=end

