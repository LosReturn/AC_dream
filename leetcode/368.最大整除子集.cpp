/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */
#include  <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // template<typename T>
    // struct cmp
    // {
    //     bool operator()(const T& x, const T& y)
    //     {
    //         return x < y;
    //     }
    // };

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        if(nums.size() == 1)
        {
            return nums;
        }

        int sz = 0, val = INT_MIN;

        vector<int> dp(nums.size(), 1);
        for( int i = 1; i< nums.size() ; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if( nums[i] % nums[j] == 0 )
                {
                    dp[i] = max(dp[i], dp[j]+1); 
                }
            }

            if(dp[i] > sz)
            {
                val = nums[i];
                sz = dp[i];
            }
        }

        vector<int> ret;
        for(int i = 0; i < nums.size() && sz > 0; i++)
        {
            if(val % nums[i] == 0)
            {
                ret.emplace_back(nums[i]);
                sz--;
            }
        }
        return ret;
    }
};
// @lc code=end

