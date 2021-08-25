/*
 * @lc app=leetcode.cn id=1893 lang=cpp
 *
 * [1893] 检查是否区域内所有整数都被覆盖
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int lowbit(int x)
    {
        return x & -x;
    }

    bool isCovered(vector<vector<int>>& ranges, int left, int right) {

    }
};
// @lc code=end

