/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if(num == 0)    return "0";
        string ans = "";
        unsigned num2 = num;
        string s = "0123456789abcdef";
        while(num2 != 0){
            ans = s[num2 & 15] + ans;
            num2 >>= 4;
        }
        return ans;
    }
};
// @lc code=end

