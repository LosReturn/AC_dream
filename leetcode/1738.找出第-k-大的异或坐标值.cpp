/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * [1738] 找出第 K 大的异或坐标值
 */
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        //use STL  
        priority_queue<int, vector<int>, greater<int>> queue;
        vector< vector<int>> prefix(row+1, vector<int>(col+1));
        for(int i = 1; i <= row; i++ )
            for(int j = 1; j <= col; j++)
            {
                prefix[i][j] = prefix[i-1][j-1]^prefix[i][j-1]^prefix[i-1][j]^matrix[i-1][j-1];

                if(queue.size() < k)
                    queue.push(prefix[i][j]);
                else
                {
                    if(prefix[i][j]>queue.top()){
                        queue.pop();
                        queue.push(prefix[i][j]);
                    }
                }
            }
        return queue.top();
    }

    //TODO: customer Min Heap

    //TODO: Median3 sort
    
 };
// @lc code=end

