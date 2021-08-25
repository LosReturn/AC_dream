/*
 * @lc app=leetcode.cn id=847 lang=cpp
 *
 * [847] 访问所有节点的最短路径
 */

#include<vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    //BFS
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = 1 << n;
        vector<int> visited(n, vector<int>(mask));
        queue<tuple<int, int>> que;


    }
};
// @lc code=end

