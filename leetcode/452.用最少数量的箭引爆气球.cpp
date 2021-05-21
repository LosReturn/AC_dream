/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        if(points.empty())
            return 0;
        
        auto cmp = [](vector<int>& a, vector<int>& b)
        {
            return a[1] < b[1];
        };

        sort(points.begin(), points.end(), cmp);

        int cnt =1;
        int right = points[0][1];
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i][0] > right )
            {
                cnt++;
                right = points[i][1];
            }
        }
        return cnt;
    }
};
// @lc code=end

