/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
         vector<string> strNums(nums.size());
        for (auto i = 0; i < nums.size(); ++i) {
            strNums[i] = to_string(nums[i]);
        }

        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b){
            return a+b > b+a;
        });
        string ans;
        for (const auto& strNum : strNums) {
            ans += strNum;
        }

        if (ans.length() > 0 && ans[0] == '0') {
            return "0";
        }

        return ans;
    }
    // string largestNumber(vector<int>& nums) {
    //     sort(nums.begin(),nums.end(), [](const int&a, const int& b)
    //     {
    //         long sa = 10, sb =10;
    //         while(a>=sa)    
    //             sa*=10;
    //         while (b>=sb)
    //         {
    //             sb*=10;
    //         }

    //         return a*sb+b > b*sa+a;
    //     });

    //     if(!nums[0])
    //         return "0";
    //     string ret="";
    //     for(auto& num : nums)
    //     {
    //         ret+= to_string(num);
    //     }
    //     return ret;

    // }
};
// @lc code=end

