/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = newInterval[0];
        int r = newInterval[1];
        bool isInter = false;
        vector<vector<int>> ret;
        for(int i = 0; i < intervals.size(); i++ )
        {
            if( intervals[i][0] > r)
            {
                if(!isInter)
                {
                    isInter = true;
                    ret.emplace_back(vector<int>({l,r}));
                }
                ret.push_back(intervals[i]);
            }
            else if(intervals[i][1] < l)
            {
                ret.push_back(intervals[i]);
            }
            else
            {
                l = min(intervals[i][0], l);
                r = max(intervals[i][1], r);
            }
        }

        if(!isInter)
            ret.emplace_back(vector<int>({l,r}));
        return ret;
    }
};
// @lc code=end

