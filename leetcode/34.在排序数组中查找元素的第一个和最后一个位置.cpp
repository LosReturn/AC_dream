/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        if(nums.size() == 0)
            return ret;
        int left = upper_lower(nums, target, 0, false);
        if (left == nums.size() || nums[left] != target)
            return ret;
        int right = upper_lower(nums, target, left, true);
        return {left, right-1};
    }

    int upper_lower(vector<int>& nums, int target,int start, bool isUpper)
    {
        int l = start, r = nums.size();
        while (l<r)
        {
            int pivot = (l+r)/2;
            if(nums[pivot] > target || (!isUpper && nums[pivot] == target))
                r = pivot;
            else
                l = pivot +1;
        }
        return l;
    }
};
// @lc code=end

