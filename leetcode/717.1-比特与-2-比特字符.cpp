/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int ret = 0;
        int curr = bits.size() -2;
        while(curr >= 0 && bits[curr])
        {
            curr--;
            ret^=1;
        }
                
        return ret == 0;
    }
};
// @lc code=end

