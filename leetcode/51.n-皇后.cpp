/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col;
        vector<int> x1y;
        vector<int> x2y;
        vector<vector<string> > ret;
        vector<int> que(n);

        dfs(ret, col, x1y, x2y, 0, n);
        return ret;
    }

    void dfs(vector<vector<string> >& ret, vector<int>& col, vector<int>& x1y, vector<int>& x2y, int curr, int n);
    {
        if(curr == n)
        {
            ret.push_back(generate(que));
            return;
        }

        for(int i =0 ; i < n; i++)
        {
            
        }

    }

    vector<string> generate(vector<int>& que)
    {
        vector<string> ret;
        for(int i = 0; i < que.size(); i++)
        {
            string tmp ="";
            for(int j = 0; j < que.size(); j++)
                if( j == que[i])
                    tmp += "Q";
                else
                    tmp += ".";
            ret.push_back(tmp);
        }
        return ret;
    }
};
// @lc code=end

