/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int left =0, right = height.size()-1;
        int lborder = 0, rborder = 0;
        int ret = 0;
        while (left < right)
        {
            if(height[left] < height[right])
            {
                if(height[left] > lborder)
                    lborder = height[left];
                else
                    ret += lborder - height[left];
                left++;
            } 
            else
            {
                if(height[right] > rborder)
                    rborder = height[right];
                else
                    ret += rborder - height[right];
                right--;
            }
        }
        return ret;
    }
};
// @lc code=end

