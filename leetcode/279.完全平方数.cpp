/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start

/*
    Bachet's conjecture states that every natural number can be 
    represented as the sum of four integer squares.
    so,max dp[n] = 4
*/

class Solution {
public:
    //fullfil bagpack dp
    int numSquaresDp(int n) {
        vector<int> dp(n+1, n);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 1; j*j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }

    bool isComplete(const unordered_map<int, int>& map, int n, int cnt)
    {
        if(cnt == 1)
            return map.count(n);
        
        for(auto it = map.begin(); it != map.end(); it++)
        {
            if( isComplete(map, n - (it->first), cnt-1))
                return true;
        }
        return false;
    }

    // force 
    /*
     *588/588 cases passed (16 ms)
     *Your runtime beats 96.07 % of cpp submissions
    */
    int numSquaresForce(int n) {
        unordered_map<int, int> map;
        for( int i = 1; i <= sqrt(n); i++)
            map[i*i] = 1;

        for(int cnt = 1; cnt <= 4; cnt++)
        {
            if( isComplete(map, n, cnt) )
                return cnt;
        }
        return -1;
    }

    // Math in leetcode solution
    /*
     Only n = 4^k * (8*m+7) , it wounld return 4. so We can check it.
    */

    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    bool checkAnswer4(int x) {
        while ( !(x & 3)) x >>= 2;
        
        return (x & 7) == 7;
    }

   int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }

        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3;
    }
};
// @lc code=end

