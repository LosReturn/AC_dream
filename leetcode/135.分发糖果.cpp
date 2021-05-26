/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    //twice query
    int candy2(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n,1);
        for(int i = 1; i < n; i++)
        {
            if( ratings[i] > ratings[i-1])
                candy[i] = candy[i-1]+1;
        }

        int sum = candy[n-1];
        int curr = 1;
        for(int i =n-2; i>=0; i--)
        {
            if(ratings[i] > ratings[i+1])
                curr++;
            else
                curr = 1;
            sum += max(candy[i], curr);
        }

        return sum;
    }

    // once query
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                ret += dec;
                pre = 1;
            }
        }
        return ret;
    }

};
// @lc code=end

