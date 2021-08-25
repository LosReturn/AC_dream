/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int absent = 0;
        int cnt = 0;
        bool ret = true;
        for(char ch : s)
        {

            if( ch == 'L')
            {
                cnt++;
                if(cnt>2)
                    return false;
            }
            else
            {
                cnt = 0;
            }

            if(ch == 'A')
            {
                absent++;
                if(absent>1)
                    return false;
            }      

        }
        return ret;
    }
};
// @lc code=end

