/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> queue;
        vector<vector<int>> ret;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, ret, queue, 0, target);
        return ret;
    }

    void dfs(vector<int>& candidates,vector<vector<int>>& ret, vector<int> queue, int start, int target)
    {
        if(target == 0)
        {
            ret.emplace_back(queue);
            return;
        }

        for(int i=start; i < candidates.size();i++)
        {
            if(target - candidates[i] < 0) 
                return;
            if (i > start && candidates[i-1] == candidates[i])
                continue;
            queue.emplace_back(candidates[i]);
            dfs(candidates, ret, queue, i+1, target-candidates[i]);
            queue.pop_back();
        }
    }
};
// @lc code=end

