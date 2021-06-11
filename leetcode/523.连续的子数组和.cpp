/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n < 2)
            return false;

        if((n+1)/2 > k)
            return true;

        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for(int i = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % k;
            /*The count function is used to count the number of times the key value appears in the unordered_map.
             In fact, c++ unordered_map does not allow duplicate keys.
              Therefore, if the key exists returns 1, else  returns 0.*/
            // It's not a good way to use find in this situation 
            if( hash.count(sum))
            {
                if( (i - hash[sum]) >= 2)
                    return true;
            }
            else 
                hash[sum] = i;
        }
        return false;
    }
};
// @lc code=end

