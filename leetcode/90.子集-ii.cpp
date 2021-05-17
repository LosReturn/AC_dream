/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> temp;
public:
    void dfs(bool choosen, int curr, vector<int>& nums)
    {
        if( curr == nums.size())
        {
            ret.emplace_back(temp);
            return;
        }
        dfs(0, curr+1, nums);
        if(!choosen && curr > 0 && nums[curr-1] == nums[curr])
        {
            return;
        }
        temp.emplace_back(nums[curr]);
        dfs(1,curr+1,nums);
        temp.pop_back();
    }
    

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        dfs(0,0,nums);
        return ret;
    }
};
// @lc code=end

