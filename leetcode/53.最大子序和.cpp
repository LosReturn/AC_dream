/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
// treee
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r)
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, l.rSum+ r.iSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
    // int maxSubArray(vector<int>& nums) {
    //     int prev = 0;
    //     int ret = nums[0];
    //     for(int i=0; i< nums.size(); i++)
    //     {
    //         prev = max(prev+nums[i], nums[i]);
    //         ret = max(ret,prev);
    //     }
    //     return ret;
    // }
};
// @lc code=end

