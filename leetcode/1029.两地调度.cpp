/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        auto cmp = [](vector<int>& cost1, vector<int>& cost2)
        {
            return (cost1[0] - cost1[1]) < (cost2[0] - cost2[1]);
        };

        sort(costs.begin(), costs.end(), cmp);
        int n = costs.size();
        int sum = 0;
        for(int i = 0; i < n/2; i++)
        {
            sum+= costs[i][0]  + costs[n-i-1][1];
        }
        return sum;
    }
};
// @lc code=end

