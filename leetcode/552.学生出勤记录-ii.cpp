/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

#include<vector>
using namespace std;



// @lc code=start

#define vvL vector<vector<long> >

class Solution {
public:
    static constexpr int MOD = 1e9+7;

    vvL fast_pow(vvL mat, int n)
    {
        vvL ret = {{1,0,0,0,0,0}};

        while(n)
        {
            if(n&1)
            {
                ret = multi(ret, mat);
            }
            n >>= 1;
            mat = multi(mat, mat);
        }
        return ret;
    }

    vvL multi(vvL a, vvL b)
    {
        int row= a.size();
        int col = b[0].size();
        int inner = b.size();

        vvL ret(row, vector<long>(col));

        for(int i = 0; i < row; i++)
            for( int j = 0; j < col; j++)
                for(int k = 0; k < inner; k++)
                {
                    ret[i][j] += a[i][k] * b[k][j];
                    ret[i][j] %= MOD;
                }
        return ret;
    }

    int checkRecord(int n) {
        
        vvL matrix = {{1,1,0,1,0,0},{1,0,1,1,0,0},{1,0,0,1,0,0},{0,0,0,1,1,0},{0,0,0,1,0,1},{0,0,0,1,0,0}};

        auto ret = fast_pow(matrix, n);

        long sum = accumulate(ret[0].begin(), ret[0].end(), 0ll);

        return (int)(sum % MOD);
    }
};
// @lc code=end

