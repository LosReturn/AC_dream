/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        int curr = 0;
        int lens = s.size();
        while(s[lens-1] == ' ' && lens > 0 ) lens--;
        for(int i = lens-1 ; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                curr++;
            }
            else
            {
                ret = max(ret, curr);
                curr = 0;
            }
        }
        return ret;
    }
};
// @lc code=end

