#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    //DP 2d
    int numWaysDp2(int n, vector<vector<int>>& relation, int k) {

        vector< vector<int> > dp(k+1, vector<int>(n,0));
        dp[0][0] = 1;

        for( int i = 0; i < k; i++)
        {
            for(auto& pair : relation)
            {
                dp[i+1][pair[1]] += dp[i][pair[0]];
            }
        }
        return dp[k][n-1];
    }

    //Dp 1d
    int numWaysDp1(int n, vector<vector<int>>& relation, int k) {

        vector<int> dp(n);
        dp[0] = 1;

        for( int i = 0; i < k; i++)
        {
            vector<int> next(n);
            for(auto& pair : relation)
            {
                next[pair[1]] += dp[pair[0]];
            }
            std::swap(dp, next);
        }
        return dp[n-1];
    }
    //TODO complete the DFS
    int numWaysDFS(int n, vector<vector<int>>& relation, int k) {

    }
    //TODO complete the BFS
    int numWaysBFS(int n, vector<vector<int>>& relation, int k) {

    }
};
// @lc code=end