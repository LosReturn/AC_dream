/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if( n<=0) return vector<vector<int>>();
        vector<vector<int>> ret(n,vector<int>(n,0));
        
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        int numEle =n*n;
        int curr = 1;
        while (numEle >= 1) {
            for (int i = left; i <= right && numEle >= 1; i++) {
                ret[top][i] = curr;
                curr++;
                numEle--;
            }
            top++;
            for (int i = top; i <= bottom && numEle >= 1; i++) {
                ret[i][right] = curr;
                curr++;
                numEle--;
            }
            right--;
            for (int i = right; i >= left && numEle >= 1; i--) {
                ret[bottom][i] = curr;
                curr ++;
                numEle--;
            }
            bottom--;
            for (int i = bottom; i >= top && numEle >= 1; i--) {
                ret[i][left] = curr;
                curr++;
                numEle--;
            }
            left++;
        }
        return ret;
    }
};
// @lc code=end

