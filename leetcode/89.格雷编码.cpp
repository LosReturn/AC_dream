/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> grayCode1(int n) {
        vector<int> code(1);

        for(int i =0; i<n;i++)
        {
            int h_bit = 1 << i;
            for(int j = code.size()-1; j>=0; j--)
                code.push_back(code[j]+h_bit); 
        }
        return code;
    }

    vector<int> grayCode(int n) {
        vector<int> code(1<<n);

        for(int i =0; i<(1<<n);i++)
        {
           code[i] = i^(i>>1);
        }
        return code;
    }

};
// @lc code=end

