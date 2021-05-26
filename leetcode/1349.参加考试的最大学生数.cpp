/*
 * @lc app=leetcode.cn id=1349 lang=cpp
 *
 * [1349] 参加考试的最大学生数
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int __cnt1__(int n)
    {
        n = (n&0x55555555) + ((n>>1)&0x55555555); 
        n = (n&0x33333333) + ((n>>2)&0x33333333); 
        n = (n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f); 
        n = (n&0x00ff00ff) + ((n>>8)&0x00ff00ff); 
        n = (n&0x0000ffff) + ((n>>16)&0x0000ffff); 
    
        return n; 
    }

    int maxStudents(vector<vector<char>>& seats) {
        int n = seats[0].size(), rows = seats.size();
        vector<vector<int>> dp(rows+1, vector<int>(1 << n));

        for(int i = 0; i < rows; i++)
        {
            int state = 0;
            for(int j = 0; j < n; j++)
            {
                state <<= 1;
                if(seats[i][j] == '.')
                    state |= 1;
            }
            // enumerate the curr line's state 
            for(int j = state; j > 0; j = (--j)&state)
            {
                //condition
                if( j & (j << 1) || j & (j >> 1))
                    continue;
                int cnt = __cnt1__(j);
                // enumerate the previous line
                for(int k = 0; k < (1 << n); k++)
                {
                    //condition
                    if( (k << 1) & j || (k >> 1) & j)
                        continue;
                    dp[i+1][j] = max(dp[i+1][j], dp[i][k] + cnt);
                }
            }
            dp[i+1][0] = *max_element(dp[i].begin(), dp[i].end());
        }
        return *max_element(dp[rows].begin(), dp[rows].end()); 
    }

    // And I found a better way shared by others
};
// @lc code=end

