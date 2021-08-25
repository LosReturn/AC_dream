/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    //naive
    int uniquePathsNaive(int m, int n) {

        vector<vector<int>> mat(m, vector<int>(n,1));
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }

        return mat[m-1][n-1];
    }

    int uniquePaths(int m, int n)
    {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};
// @lc code=end

