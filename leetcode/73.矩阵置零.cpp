/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();

        bool c_0 = false;

        for(int i = 0; i < m; i++)
        {
            if( !matrix[i][0])
                c_0 = true;
            for(int j = 1; j<n; j++)
            {
                if(!matrix[i][j])
                    matrix[0][j] = matrix[i][0] = 0;
            }
        }

        for(int i = m-1; i >= 0; i--)
        {
            for(int j = 1; j < n; j++)
            {
                if( !matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }

            if(c_0)
                matrix[i][0] = 0;
        }
    }
};
// @lc code=end

