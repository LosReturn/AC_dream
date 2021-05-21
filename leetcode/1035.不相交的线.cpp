/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));

        for(int i = 1; i <= nums1.size(); i++)
            for(int j = 1; j <= nums2.size(); j++)
            {
                dp[i][j] = nums1[i-1] == nums2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
            }
        
        return dp[nums1.size()][nums2.size()];
    }
};
// @lc code=end

