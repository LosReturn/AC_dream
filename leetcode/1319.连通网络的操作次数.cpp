/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */
#include <vector>
using namespace std;
// @lc code=start

class unionFind {
private:
    vector<int> tree;
    int size;
    int redundant;
public:
    unionFind(int n): tree(n,0)
    {
        for(int i = 1; i < n; i++ )
            tree[i] = i;
        size = n;
        redundant = 0;
    }
    
    void Union(int id1, int id2)
    {
        int root1 = find(id1);
        int root2 = find(id2);
        if(root1 != root2)
        {
            tree[find(id1)] = find(id2);
            size--;
        }
        else
            redundant++;
    }

    int find(int idx)
    {
        if( idx == tree[idx])
            return idx;
        tree[idx] = find(tree[idx]);
        return tree[idx];
    }

    int sizeHint()
    {
        return size;
    }

    int redundantHint()
    {
        return redundant;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int num = connections.size();
        unionFind uf(n);
        
        for(vector<int>& pairs : connections)
        {
            uf.Union(pairs[0], pairs[1]);
        }

        if(uf.sizeHint() == 1)
            return 0;
          
        return uf.redundantHint() - uf.sizeHint() + 1 >= 0 ? uf.sizeHint() - 1 : -1;
    }
};
// @lc code=end

