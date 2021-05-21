/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    //use DP
    int eraseOverlapIntervalsDp(vector<vector<int>>& intervals) {
        
        if (intervals.empty())
            return 0;

        //normally use auto better
        std::function<bool(vector<int>&, vector<int>&)> cmp = [](vector<int>& a, vector<int>& b)
        {
            return a[0] < b[0];
        };

        sort(intervals.begin(), intervals.end(), cmp);

        vector<int> dp(intervals.size(), 1);

        for( int i = 1; i< intervals.size(); i++)
        {
            for( int j =0; j < i; j++)
                if(intervals[j][1] <= intervals[i][0])
                    dp[i] = max(dp[i], dp[j]+1);
        }

        return intervals.size() - *max_element(dp.begin(), dp.end());

    }

    //sort and opti
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if (intervals.empty())
            return 0;

        //normally use auto better
        std::function<bool(vector<int>&, vector<int>&)> cmp = [](vector<int>& a, vector<int>& b)
        {
            return a[1] < b[1];
        };

        sort(intervals.begin(), intervals.end(), cmp);

        int right = intervals[0][1];
        int ret = 1;

        for( int i = 1; i< intervals.size(); i++)
        {
            if(intervals[i][0] >= right)
            {
                ret++;
                right = intervals[i][1];
            }
        }

        return intervals.size() - ret;
    }
};

// @lc code=end

