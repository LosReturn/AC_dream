/*
 * @lc app=leetcode.cn id=1646 lang=cpp
 *
 * [1646] 获取生成数组中的最大值
 */

// @lc code=start
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 0)
        {
            return 0;
        }

        vector<int> nums(n+1, 0);
        int ret = 1;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            nums[i] = nums[i/2] + (i%2) * nums[i/2+1];
            ret = max(ret, nums[i]);
        }
        return ret;
    }
};
// @lc code=end

