/*
 * @lc app=leetcode.cn id=1583 lang=cpp
 *
 * [1583] 统计不开心的朋友
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> nn(n, vector<int>(n));
        vector<int> match(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n-1 ; j++)
                nn[i][preferences[i][j]] = j;
        
        for(auto& pair:pairs)
        {
            match[pair[0]] = pair[1];
            match[pair[1]] = pair[0];
        }

        int cnt = 0;

        for(int i=0; i < n; i++)
        {
            int j = match[i];
            int idx = nn[i][j];

            for(int k=0; k < idx; k++)
            {
                int u = preferences[i][k];
                int v = match[u];
                if( nn[u][v] > nn[u][i])
                {
                    ++cnt;
                    break;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

