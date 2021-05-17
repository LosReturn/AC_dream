/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
   vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vec;
        vector<bool> choosen(nums.size(),0);
        sort(nums.begin(), nums.end());
        dfs(ret, vec, choosen, nums);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int>& vec, vector<bool>& choosen, vector<int>& nums)
    {
        if(vec.size()==nums.size())
        {
            ret.emplace_back(vec);
            return;
        }

        for(int i =0; i < nums.size(); i++)
        {
            if(choosen[i])
                continue;
            if(i>0 && !choosen[i-1] && nums[i] == nums[i-1])
                continue;
            vec.push_back(nums[i]);
            choosen[i] = 1;

            dfs(ret, vec, choosen, nums);

            vec.pop_back();
            choosen[i] = 0;
        }
    }
};
// @lc code=end

