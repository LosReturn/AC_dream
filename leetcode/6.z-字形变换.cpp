/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> data(min( numRows, int(s.size())));
        int curr = 0;
        
        for(int i =0; i < s.size(); i++)
        {
            data[curr] += s[i];
            if((i/numRows)%2)
                curr++;
            else 
                curr--;
        }

        string ret;
        for (string row : data) ret += row;
        return ret;
    }
};
// @lc code=end

