/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        int m = primes.size();

        vector<int> dp(n+1);
        dp[1] = 1;
        priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > heap;
        for(int i=0; i<m; i++)
            heap.emplace(primes[i], 1);

        for (int i = 2; i < n + 1;) {
            auto [val, idx] = heap.top();
            heap.pop();
            if (val != dp[i - 1]) dp[i++] = val;
            heap.emplace(val / dp[idx] * dp[idx + 1], idx + 1);
        }
        return dp[n];
    }
};
// @lc code=end

