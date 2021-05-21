/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        for(int i =0, j=0; i < g.size() && j < s.size();i++,j++)
        {
            while(j < s.size() && s[j] < g[i]) j++;

            if(j < s.size())
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

