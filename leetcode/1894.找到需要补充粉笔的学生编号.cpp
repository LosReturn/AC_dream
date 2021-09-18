/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        int n = chalk.size();
        vector<int> prefix(n);
        prefix[0] = chalk[0];

        if (prefix[0] > k) {
            return 0;
        }

        for(int i = 1; i<n; i++)
        {
            prefix[i] = prefix[i-1] + chalk[i];
            if(prefix[i] > k)
                return i;
        }

        k = k % prefix[n-1];

        return upper_bound(prefix.begin(), prefix.end(), k) - prefix.begin();

    }
};
// @lc code=end

