/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */
#include <vector>
using namespace std;
// @lc code=start
// class Solution {
// public:
//     int shipWithinDays(vector<int>& weights, int D) {

//         int lens = weights.size();

//         vector<int> sum(weights);
//         int max_w = weights[0];

//         for(int i = 1; i < lens; i++)
//         {
//             sum[i] = sum[i-1] + weights[i];
//             max_w = max(max_w, weights[i]);
//         }

//         int left = max_w;
//         int right = sum[lens-1];
//         while(left < right)
//         {
//             int mid = left + right >> 1;

//             if([=]()->bool{

//                 int cnt = 0;
//                 int last = 0;
//                 for(int i = 0; i < lens; cnt++)
//                 {
//                     while( i < lens && (mid + last - sum[i]) >= 0 )
//                     {
//                         i++;
//                     }
//                     last = sum[i-1];
//                 }

//                 return cnt <= D;
//             }())
//                 right = mid;
//             else
//                 left = mid +1;
//         }
//         return right;
//     }
// };

class Solution {
public:
    int getDay(vector<int>& weights, int speed) {
        int res = 1;
        int tmp = 0;

        for (int weight : weights) {
            tmp += weight;
            if (tmp > speed) {
                res++;
                tmp = weight;
            }
        }

        return res;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int left = 1;
        int right = 0;
        for (auto& weight : weights) {
            left = max(left, weight);
            right += weight;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (getDay(weights, mid) <= D) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end

