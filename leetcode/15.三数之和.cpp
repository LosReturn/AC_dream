/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> ret;
        for(int i =0; i < len-2; i++)
        {
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            int target = -nums[i];
            int l = i+1, r = len-1;

            while(l < r)
            {
                int value = nums[l]+nums[r];
                if( value > target )
                    r--;
                else if(value < target)
                    l++;
                else
                {
                    ret.push_back(vector<int>({-target,nums[l],nums[r]}));
                    while(l<r && nums[l]==nums[l+1])
                        l++;
                    l++;
                    while(l<r && nums[r-1]==nums[r])
                        r--;
                    r--;
                }

            }

        }
        return ret;
    }
};
// @lc code=end

