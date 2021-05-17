/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i]>0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1] )
                swap( nums[i], nums[nums[i] - 1]);
        }
         for(int i = 0; i < nums.size(); i++)
         {
             if(nums[i] != i+1)
                return i+1;
         }
    }
};
// @lc code=end

