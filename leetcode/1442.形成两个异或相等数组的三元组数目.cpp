/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> cnt, total;
        int ret = 0, s = 0;
        for (int k = 0; k < n; ++k) {
            int val = arr[k];
            if (cnt.count(s ^ val)) {
                ret += cnt[s ^ val] * k - total[s ^ val];
            }
            ++cnt[s];
            total[s] += k;
            s ^= val;
        }
        return ret;
    }
};
// @lc code=end

