/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        auto cmp = [](vector<int>& box1,  vector<int>& box2)
        {
            return box1[1] > box2[1];
        };

        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int sum = 0;
        int sz = truckSize;
        for(int i = 0; i<boxTypes.size() && sz > 0; i++)
        {
            if(sz > boxTypes[i][0])
            {
                sz -= boxTypes[i][0];
                sum += boxTypes[i][0]*boxTypes[i][1];
            }
            else
            {
                sum += sz * boxTypes[i][1];
                sz = 0;                
            }

        }
        return sum;
    }
};
// @lc code=end

