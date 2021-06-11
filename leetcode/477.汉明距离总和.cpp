/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();

        for(int i = 0; i < 30; i++)
        {
            int cnt = 0;
            for(auto ch : nums)
            {
                if((ch >> i) & 1) 
                    cnt++;
            }
            ret += cnt*(n-cnt);
        }
        return ret;
    }
};
// @lc code=end

