/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int odd = 0;
        for( int i = 0; i < n; i++)
        {
            if(position[i] % 2)
                odd++;
        }
        return min(odd, n - odd);
    }
};
// @lc code=end

