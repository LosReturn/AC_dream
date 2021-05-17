/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 */

#include <vector>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    /*
    //direct
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int width = matrix[0].size(), height = matrix.size();
        
        vector<vector<int>> sum(height+1, vector<int>(width+1, 0));
        
        //edge
        //for(int i = 1; i< width; i++)
        //    sum[0][i] += sum[0][i-1];
        //for(int i = 1; i< height; i++)
        //    sum[i][0] += sum[i-1][0];
        
        for(int i = 1; i < height + 1; i++)
            for(int j = 1; j < width + 1; j++)
                sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        
        int ans = INT_MIN;
        int curr;
        for(int i = 1; i <= height; i++)
            for(int j = 1; j <= width; j++)
                for(int m = 1; m <= height; m++)
                    for(int n = 1; n <= width; n++)
                    {
                        curr = sum[m][n] + sum[i-1][j-1] - sum[i-1][n] - sum[m][j-1]; 
                        if(curr <= k)
                            ans = max(curr, ans);       
                    }
        return ans;
    }
    */

    // binary
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int width = matrix[0].size(), height = matrix.size();
        
        vector<vector<int>> sum(height+1, vector<int>(width+1, 0));

        for(int i = 1; i < height + 1; i++)
            for(int j = 1; j < width + 1; j++)
                sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        
        int ans = INT_MIN;
        int curr;
        bool isSwap = false;
        if( height > width)
        {
            swap(width, height);
            isSwap = true;
        }
        // definite top and bottom edge
        for(int i = 1; i <= height; i++)
            for(int j = i; j <= height; j++)
            {
                // definite right edge 
                set<int> box;
                box.insert(0);
                for(int l = 1; l <= width; l++)
                {
                    int aera = isSwap? sum[l][j] - sum[l][i-1] : sum[j][l] - sum[i-1][l]  ;
                    std::set<int>::iterator ptr = box.lower_bound(aera - k);    
                    if( ptr != box.end())
                    {
                        curr = aera - *ptr;
                        ans = max(curr, ans);
                    } 
                    box.insert(aera);      
                }
            }
        return ans;
    }
};
// @lc code=end

