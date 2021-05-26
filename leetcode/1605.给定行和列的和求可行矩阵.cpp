/*
 * @lc app=leetcode.cn id=1605 lang=cpp
 *
 * [1605] 给定行和列的和求可行矩阵
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size(), col = colSum.size();

        vector<vector<int>> ret(row, vector<int>(col,0));

        int i = 0, j =0;
        while( i < row && j < col)
        {
            int val = min(rowSum[i], colSum[j]);
            ret[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;

            if(rowSum[i] == 0)
                i++;
            if(colSum[j] == 0)
                j++;
        }

        return ret;
    }
};
// @lc code=end

