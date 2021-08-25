/*
 * @lc app=leetcode.cn id=1711 lang=cpp
 *
 * [1711] 大餐计数
 */
#include <vector>
using namespace std;
#include <unordered_map>

// @lc code=start
class Solution {
    const int MOD = 1e9+7;
    const int BIT_LENGTH_TABLE[32] = {
            1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
            5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5
    };
    const int maxNum = 1 << 22;

    int high_bit(unsigned long x)
    {

        int msb = 0;
        while (x >= 32) {
            msb += 6;
            x >>= 6;
        }
        msb += BIT_LENGTH_TABLE[x];
        return 1 << (msb-1);
    }
public:
    int countPairsHASH(vector<int>& deliciousness) {
        unordered_map<int, int> cnt;
        int ret = 0;

        for(auto& val: deliciousness)
        {

            for( int i = high_bit(val); i < maxNum; i <<= 1)
            {
                int t = i - val;
                if(cnt.count(t))
                {
                    ret += cnt[t];
                    if(ret >= MOD)
                        ret -= MOD;
                }
            }
            cnt[val]++;
        }
        return ret;
    }

    int countPairs(vector<int>& deliciousness) {
        int ans = 0;
        int f[(1 << 22) + 1] = {0,};
        for(int & x: deliciousness)
            ++f[x];
        /*
        int maxn = 0;
        for(int & x:d)
           maxn = max(maxn, x)
        maxn <<= 2;
        maxn = high_bit(maxn);
        */
        for(int & x: deliciousness){
            --f[x];
            // for(int i = high_bit(x); i < maxn; i <<= 1){
            for(int i = high_bit(x); i < (1 << 22); i <<= 1){
                if(i < x) continue; 
                ans = (ans + f[i - x])%MOD; 
            }
        }
        return ans % MOD;
    }
};
// @lc code=end

