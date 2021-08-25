/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

#include <vector>
#include <functional>
using namespace std;

// @lc code=start
class Solution {
public:
    //Tri-color_marking GC
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> color(n);

        std::function<bool(int)> gc = [&](int x)->bool
        {
            if(color[x])
                return color[x] == 2;

            color[x] = 1;

            for(auto& y: graph[x])
            {
                if(!gc(y))
                    return false;
            }

            color[x] = 2;
            return true;
        };

        vector<int> ret;

        for(int i = 0; i< n; i++)
            if(gc(i))
                ret.push_back(i);
        return ret;
    }

};
// @lc code=end

