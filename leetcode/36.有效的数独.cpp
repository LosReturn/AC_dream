/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<int> column(9);
        vector<int> row(9);
        vector<int> box(9);

        for(int i = 0; i< 9; i++)
            for(int j = 0; j<9; j++)
            {
                char ch = board[i][j];
                if( ch == '.')  
                    continue;
                
                int num = ch - '0';
                int idx = i/3*3 + j/3;

                if(((row[i] >> num) & 1) || ((column[j] >> num) & 1) || ((box[idx] >> num) & 1))
                    return false;

                row[i] |= (1<<num);
                column[j] |= (1<<num);
                box[idx] |= (1<<num);
            }
        return true;
    }
};
// @lc code=end

