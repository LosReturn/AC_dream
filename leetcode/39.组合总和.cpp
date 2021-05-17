/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> queue;
        vector<vector<int>> ret;
        int sum = 0;
        int len = candidates.size();
        function<void(int)> dfs = [&](int curr)
        {
            if(sum == target)
                ret.emplace_back(queue);
            
            if(sum >= target)
                return;
            
            for(int i= curr; i < len; i++)
            {
                queue.push_back(candidates[i]);
                sum += candidates[i];
                dfs(i);
                sum -= candidates[i];
                queue.pop_back();
            }
        };
        dfs(0);
        return ret;
    }
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<int> queue;
    //     vector<vector<int>> ret;
    //     sort(candidates.begin(), candidates.end());
    //     dfs(candidates, ret, queue, target);
    //     return ret;
    // }

    // void dfs(vector<int>& candidates,vector<vector<int>>& ret, vector<int> queue, int start, int target)
    // {
    //     if(target == 0)
    //     {
    //         ret.emplace_back(queue);
    //         return;
    //     }

    //     for(int i=start; i < candidates.size();i++)
    //     {
    //         if(target - candidates[i] < 0)
    //             return;
    //         queue.emplace_back(candidates[i]);
    //         dfs(candidates, ret, queue, i, target-candidates[i]);
    //         queue.pop_back();
    //     }
    // }
};
// @lc code=end

