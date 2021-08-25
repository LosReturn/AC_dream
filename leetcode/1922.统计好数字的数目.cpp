class Solution {
    const int MOD = 1e9 + 7;
public:

    long long quickPow(long long a, long long b)
    {
        long long ret = 1;
        while(b)
        {
            if( b&1 )
                ret = (ret * a) % MOD;
            a *= a;
            a %= MOD;
            b >>= 1;
        }
        return ret;
    }

    int countGoodNumbers(long long n) {
        long long x = n/2;
        return (quickPow(4 , x) * quickPow(5, n-x)) % MOD;
    }
};