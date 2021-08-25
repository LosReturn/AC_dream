/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSubarraysWithSumPrefix(vector<int>& nums, int goal) {
        unordered_map<int, int> cnt;
        cnt[0]++;
        int n = nums.size();
        vector<int> prefix(n+1, 0);

        for(int i=0; i<n; i++)
            prefix[i+1] = prefix[i] + nums[i];
        // r - l = sum
        int r,l;
        int ret = 0;
        for(int i =0; i<n; i++)
        {
            r = prefix[i+1];
            if(r >= goal){
                l = r - goal;
                if( cnt.count(l))
                    ret += cnt[l];
            }
            cnt[r]++;
        }
        return ret;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        vector<int> idx;
        int n = nums.size();
        for( int i=0; i < n; i++)
            if(nums[i])
                idx.push_back(i);
        idx.push_back(n);
        int nn = idx.size();
        int l=0, r;
        int ret = 0; 
        for( int i = 0; i <n; i++)
        {   
            r = l+goal;
            if( r >= nn)
                break;
            ret += idx[r] - ( goal? idx[r-1] : i);
            l += nums[i];
        }   
        return ret;
    }
};
// @lc code=end

