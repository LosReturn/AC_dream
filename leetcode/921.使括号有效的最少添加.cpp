/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int sum = 0;
        for(auto& ch : s)
        {
            sum += ch == '(' ? 1:-1;
            if(sum < 0)
            {
                sum++;
                ans++;
            }
        }
        ans += sum;
        return ans;
    }
};
// @lc code=end

