/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> pos;
        queue<pair<char, int>> que;

        for(int i = 0; i < s.size(); i++)
        {
            if( ! pos.count(s[i]))
            {
                pos[s[i]] = i;
                que.emplace( std::pair(s[i],i));
            }
            else{
                pos[s[i]] = -1;
                while( !que.empty() && pos[que.front().first] == -1)
                    que.pop();
            }
        }
        return que.empty() ? -1 : que.front().second;
    }
};
// @lc code=end

