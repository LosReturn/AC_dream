/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    //find the inverse element
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int pos = 1;

        while( pos < str.size() && str[pos-1] <= str[pos] )
            pos++;
        
        if( pos < str.size())
        {
            while( pos > 0 && str[pos] < str[pos-1])
            { 
                str[pos-1]--;
                pos--;
            }

            for( int i = pos+1; i < str.size(); i++)
            {
                str[i] = '9';
            }
        }
        return atoi(str.c_str());
    }
};
// @lc code=end

