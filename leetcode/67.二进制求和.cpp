/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ret("");
        for(int i = a.size()-1, j = b.size()-1; i>=0 || j>=0; --i, --j)
        {
            if( i >= 0)
                carry += a[i] - '0';
            if(j>=0)
                carry += b[j] - '0';
            ret = to_string(carry & 1) + ret;
            carry >>= 1;
        }
        return carry? '1'+ret : ret;
    }

    string addBinary2(string a, string b) {
        bool carry = 0;
        bool val;
        string ret("");
        for(int i = a.size()-1, j = b.size()-1; i>=0 || j>=0; --i, --j)
        {
            bool num[2] = {0};
            if( i >= 0)
                num[0] = a[i] - '0';
            if(j >= 0)
                num[1] = b[j] - '0';
            
            val = (num[0]^num[1])^carry;
            ret += to_string(val);
            carry = (num[0]&num[1])&carry;
        }
        return carry? '1'+ret : ret;
    }

};
// @lc code=end

