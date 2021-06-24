/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        const int hash = 2*10000+3;
        int size = points.size();

        if(size < 3)
            return size;
        int ret = 0;

        for(int i = 0; i < size; i++)
        {
            if ( ret >= size - i)
                break;
            
            unordered_map<double, int> cnt;
            for( int j = i+1; j < size; j++)
            {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] -  points[j][1];

                if(dx == 0)
                    dy = 1;
                else if (dy == 0)
                    dx = 1;
                else
                {
                    if( dx < 0)
                    {
                        dx = -dx;
                        dy = -dy;
                    }

                    int comm = gcd( abs(dx), abs(dy));
                    dx /= comm;
                    dy /= comm;
                }
                cnt[ hash * dx + dy]++;
            }
            for ( auto it = cnt.begin(); it != cnt.end(); ++it )
                ret = max(ret, it->second + 1);
        }
        return ret;
    }

    int gcd(int a, int b)
    {
        return b ? gcd( b, a % b ) : a;
    }
};
// @lc code=end

