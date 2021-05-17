/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include < vector >
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums, int start, int end, int selected, int target) {
        vector<vector<int>> ret;
        for(int i =start; i < end-2; i++)
        {
            if(i > start && nums[i-1] == nums[i])
                continue;
            int temp = target-selected-nums[i];
            int l = i+1, r = end-1;

            while(l < r)
            {
                int value = nums[l]+nums[r];
                if( value > temp )
                    r--;
                else if(value < temp)
                    l++;
                else
                {
                    ret.push_back(vector<int>({selected, nums[i], nums[l],nums[r]}));
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

    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ret;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i< len-3; i++)
        {

            if(i > 0 && nums[i-1] == nums[i])
                continue;
            auto t = threeSum(nums,i+1,len,nums[i],target);
            ret.insert(ret.end(), t.begin(), t.end());
        }
        return  ret;
    }
};
// @lc code=end

