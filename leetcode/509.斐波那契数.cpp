/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */
#include <vector>
using namespace std;

#define vvL vector<vector<long> >
// @lc code=start
class Solution {
public:
    //DP
    int fib(int n) {
        
        int ret[2] = {1,1};

        for(int i = 2; i <n; i++)
        {
            ret[i%2] = ret[0] + ret[1];
        }

        return ret[n%2];
    }

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

    vL multi(vvL a, vvL b)
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



    int fibMatrix(int n)
    {
        if(n<2)
            return n;
        
         vvL kernel{{1, 1}, {1, 0}};
         auto ret = fast_pow(kernel,n-1);
         return ret[0][0];
    }

    int fibMath(int n)
    {
        double sqrt5 = sqrt(5);
        double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
        return round(fibN / sqrt5);
    }

};
// @lc code=end

