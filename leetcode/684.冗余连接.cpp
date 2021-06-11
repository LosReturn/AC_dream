/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void _union(vector<int>& data, int id1, int id2)
    {
        int root1 = find(data, id1);
        int root2 = find(data, id2);

        if(root1 != root2)
            data[root1]  = root2;

    }

    int find(vector<int>& data, int id)
    {
        if( data[id] == id)
            return id;
        data[id] = find(data, data[id]);
        return data[id];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int size = edges.size();
        vector<int> data(size+1);

        //init
        for(int i = 1; i < size+1; i++)
        {
            data[i] = i;
        }

        int u,v;
        for(int i = 0; i < size; i++)
        {
            u = edges[i][0];
            v = edges[i][1];
            if(find(data, u) == find(data, v))
            {
                 return {min(u,v), max(u,v)};
            }
            _union(data, u, v);
        }
        return {};
    }
};
// @lc code=end

