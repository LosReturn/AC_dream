/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <functional>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:

    // Forward
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> pipe;
        vector<vector<int>> ret;

        for (int mask = 0; mask < (1 << n); ++mask) {
            pipe.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    pipe.push_back(nums[i]);
                }
            }
            ret.push_back(pipe);
        }
        return ret;
    }

    // dfs
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ret;
        vector<int> pipe;

        function<void(int)> dfs = [&](int curr)
        {
            if(curr == n)
            {
                ret.push_back(pipe);
                return;
            }

            pipe.push_back(nums[curr]);
            dfs(curr+1);
            pipe.pop_back();
            dfs(curr+1);
        };

        
        dfs(0);
        return ret;
    }
};
// @lc code=end

