/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */



#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start

const int base[] = {1,10,100,1000}; 

class Solution {
public:
    //BFS
    int openLock(vector<string>& deadends, string target) {
        
        if( target == "0000")
            return 0;

        int vis[10000] = {0};

        for(auto& deadend: deadends)
        {
            vis[ atoi(deadend.c_str())] = 1;
        }

        if( vis[0] )
            return -1;

        auto Next = [&](int& status) -> vector<int> {
            vector<int> ret;
            for (int i = 0; i < 4; ++i) {
                int num = status / base[i] % 10;    
                
                if(num == 0)
                    ret.push_back(status + 9*base[i]);
                else
                    ret.push_back(status - base[i]);

                if(num == 9)
                    ret.push_back(status - 9*base[i]);
                else
                    ret.push_back(status + base[i]);
            }
            return ret;
        };

        int ret = 0, t = atoi(target.c_str());
        queue<int> que;
        que.push(0);
        vis[0] = 1;
        int vertex;
        while(!que.empty())
        {
            int sz = que.size();
            
            for(int i = 0; i <sz; i++)
            {
                vertex = que.front();
                que.pop();
                
                for(auto&& next_status: Next(vertex))
                {
                    if(!vis[next_status])
                    {
                        if( next_status == t)
                        {
                            return ret+1;
                        }

                        que.push(move(next_status));
                        vis[next_status] = 1;

                    }
                }
            }
            ret++;
        }
        return -1;
    }

};
// @lc code=end

