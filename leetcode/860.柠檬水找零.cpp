/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int len_five = 0, len_ten = 0;
        
        for(int bill:bills )
        {
            switch (bill)
            {
            case 5:
                len_five++;
                break;
            case 10:
                len_ten++;
                len_five--;
                break;
            case 20:
                if(len_ten>0)
                {
                    len_ten--;
                    len_five--;
                }
                else{
                    len_five -= 3;
                }
            }
            if (len_five < 0 || len_ten <0)
                return false;
        }
        return true;
    }
};
// @lc code=end

