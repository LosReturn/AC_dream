/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        
        if(s1 == "" || s2 == "" || s1.size() != s2.size())
            return -1;
        // xy means x in s1, and the same positon of s2 is y
        int xy_cnt = 0, yx_cnt = 0;

        for(int i = 0; i< s1.size(); i++)
        {
            if( s1[i] == 'x' && s2[i] == 'y')
                xy_cnt++;
            else if(s1[i] == 'y' && s2[i] == 'x')
                yx_cnt++;
        }
        if((yx_cnt+xy_cnt)%2)
            return -1;
        return (xy_cnt+1)/2 + (yx_cnt+1)/2; 
    }
};
// @lc code=end

