/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */


#include <vector>
using namespace std;
// @lc code=start

static constexpr int inf = 1e9;

class Solution {
public:

    //DP
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> paths(n, inf);
        paths[src] = 0;
        int ans = inf;

        for(int i=0; i<k+1; i++)
        {
            vector<int> g(n, inf);
            for(auto&& flight: flights)
            {
                int fi = flight[0], dj = flight[1], cost = flight[2];
                g[dj] = min(g[dj], paths[fi]+cost); 
            }

            paths = move(g);
            ans = min(ans, paths[dst]);
        }

        return ans == inf? -1 : ans;
    }
};
// @lc code=end

