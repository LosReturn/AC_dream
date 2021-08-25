/*
 * @lc app=leetcode.cn id=1818 lang=cpp
 *
 * [1818] 绝对差值和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;
    // 遍历并且去寻找该位置下最大的delta
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> q(nums1);
        sort(q.begin(), q.end());
        int n = nums1.size();
        int ret = 0, m = 0;
        int l = 0, r = n-1;
        for( int i = 0; i<n; i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            ret = (ret + diff)% MOD;

            int j = lower_bound(q.begin(), q.end(), nums2[i]) - q.begin();
            if (j < n) {
                m = max(m, diff - (q[j] - nums2[i]));
            }
            if (j > 0) {
                m = max(m, diff - (nums2[i] - q[j - 1]));
            }

        }
        return (ret - m + MOD) % MOD;
    }
};
// @lc code=end

