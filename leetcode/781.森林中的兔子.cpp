/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */
#include < vector >
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> dict;
        for (auto num:answers)
        {
            dict[num]++;
        }
        int ret = 0;
        for( auto& [y, x] : dict)
        {
            ret += (x+y)/ (y+1) * (y+1);
        }
        return ret;
    }
};
// @lc code=end

