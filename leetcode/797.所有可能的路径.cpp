/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
    vector< vector<int>> ret;
    vector<int> visited;
public:


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        visited.push_back(0);
        dfs(graph, 0, graph.size() - 1);
        return ret;
    }

    void dfs(vector<vector<int>>& graph, int start, int end)
    {
        if( start == end)
        {
            ret.emplace_back(visited);
            return;
        }

        for(auto& p: graph[start])
        {
            visited.push_back(p);
            dfs(graph, p, end);
            visited.pop_back();
        }
    }
};
// @lc code=end

