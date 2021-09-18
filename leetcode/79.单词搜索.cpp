/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <functional>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int l = word.size();
        function<bool(int,int,int)> dfs = [&](int x, int y, int cnt)
        {
            if(board[x][y] != word[cnt])
                return false;
            if(cnt == l-1)
                return true; 
            bool ret = false;
            char save = 0;
            swap(save, board[x][y]);
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if( nx >=0 && nx < m && ny >=0 && ny < n && board[nx][ny] )
                {
                    bool flag = dfs(nx, ny, cnt+1);
                    if(flag)
                    {
                        ret = true;
                        break;
                    }
                }
            }
            swap(save, board[x][y]); 
            return ret;
        };
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(dfs(i, j, 0))
                    return true;
        return false;
    }
};
// @lc code=end

