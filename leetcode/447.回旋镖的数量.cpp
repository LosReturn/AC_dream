/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        unordered_map<int, int>  cnt;
        for(auto&& x:points)
        {
            cnt.clear();
            for(auto&& y:points)
            {
                ret += 2*cnt[(x[0]-y[0])*(x[0]-y[0]) + (x[1]-y[1])*(x[1]-y[1])]++;
            }
        }
        return ret;
    }
};
// @lc code=end

