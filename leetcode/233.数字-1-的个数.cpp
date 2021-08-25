/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        
        int digit = 1;
        int ret = 0;

        int high = n/10;
        int low = 0;
        int curr = n%10;

        while( high != 0 || curr != 0)
        {
            if(curr == 0)
            {
                ret += high*digit;
            }
            else if (curr == 1)
            {
                ret += high * digit + low + 1;
            }
            else
                ret += (high+1) * digit;

            low += curr*digit;
            curr = high % 10;
            high /= 10;
            digit*=10;
        }
        return ret;
    }

    int get(vector<int>& num, int l, int r)
    {
        int res = 0;
        for (int i = l; i >= r; i -- ) 
            res = res * 10 + num[i];
        return res;
    }

    int power10(int x) 
    {
        int res = 1;
        while (x -- ) 
        {
            res *= 10;
        }
        return res;
    }

    // 统计某一个数n中x的数量
    int count(int n, int x) 
    {
        if (!n) return 0;

        vector<int> num; 
        while (n)
        {
            num.push_back(n % 10);
            n /= 10;
        }

        n = num.size();

        int res = 0;

        for (int i = n - 1 - !x; i >= 0; i -- )
        {   

            if (i < n - 1)
            {
                res += get(num, n - 1, i + 1) * power10(i);
                if (!x) res -= power10(i); 
            }

            if(num[i] == x) res += get(num, i - 1, 0) + 1;
            else if (num[i] > x) res += power10(i);
        }
        return res;
    }
    
    int countDigitOneDp(int n) {
        return count(n, 1) - count(0, 1);
    }
};
// @lc code=end

