/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size() - 2 ;
        int p = 0;
        while( l <= r)
        {
            int mid = (l + r) /2;
            if( arr[mid] > arr[mid+1])
            {
                p = mid;
                r = mid - 1;
            }
            else
                l = mid +1;
        }
        return p;
    }

    int peakIndexInMountainArrayDiff(vector<int>& arr) {
        int size = arr.size();
        int last = 0;
        for( int i = 0; i < size-1; i++)
        {
            int tmp = arr[i+1] - arr[i];
            if(last > 0 && tmp < 0)
                return i;
            last = tmp;
        }
        return 0;
    }
};
// @lc code=end

