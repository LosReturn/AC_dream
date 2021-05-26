/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    //more practical
    int matrixScore2(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        
        int ret = h * (1 << (w-1));
        for(int j = 1; j < w; j++)
        {
            int cnt = 0;
            for(int i = 0; i < h; i++)
            {
                if( grid[i][0] == 0)
                    cnt += grid[i][j]^1;
                else
                    cnt += grid[i][j];
            }
            ret += max(cnt, h-cnt)*(1<<(w-j-1));
        }
        return ret;
    }
    //navie 
    int matrixScore2(vector<vector<int>>& grid) {
        int col = grid.size();
        int row = grid[0].size();

        for(int i = 0; i < col; i++)
        {
            if( grid[i][0] == 0)
            {
                for(int j = 0; j < row; j++)
                    grid[i][j] ^= 1;
            }
        }

        for(int j = 1; j < row; j++)
        {
            int cnt = 0;
            bool swap = false;
            for(int i = 0; i < col; i++)
            {
                if(grid[i][j] == 0)
                    cnt++;
                if( cnt > col/2)
                {
                    swap = true;
                    break;
                }
                    
            }

            if(swap)
            {
               for(int i = 0; i < col; i++) grid[i][j] ^= 1; 
            }
        }
        int ret = 0;
        for(int i =0; i< col; i++ )
        {
            for(int j=0; j < row; j++)
            {
                   ret += grid[i][j] << row-j-1;
            }
        }
        return ret;
    }
};
// @lc code=end

