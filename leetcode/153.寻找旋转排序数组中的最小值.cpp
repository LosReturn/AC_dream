/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; 
        int r = nums.size()-1;
        int pivot;
        while(l<r)
        {
            pivot = l+(r-l)>>2;
            if(nums[pivot] <= nums[r])
                r = pivot;
            else
                l = pivot +1;
        }
        return nums[l];
    }
};
// @lc code=end

