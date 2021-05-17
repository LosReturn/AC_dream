/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left < right)
        {
            int pivot = (left + right)/ 2;
            if ( nums[pivot] == nums[right])
            {
                right--;
                continue;
            }

            if( nums[pivot] < nums[right])
                right = pivot;
            else 
                left = pivot+1;
        }
        return nums[left];
    }
};
// @lc code=end

