/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mid;
        while(l<r)
        {
            mid = (l+r) >> 1;
            nums[mid] < nums[mid+1] ? l = mid+1 : r = mid;
        }
        return l;
    }
};
// @lc code=end

