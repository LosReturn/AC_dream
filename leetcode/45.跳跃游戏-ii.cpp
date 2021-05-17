/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int target = 0;
        int lens = 0;
        int ret = 0;
        for(int i = 0; i < nums.size() - 1 ; i++)
        {
            lens = max(lens, i + nums[i]);
            if( i == target)
            {
                target = lens;
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end

