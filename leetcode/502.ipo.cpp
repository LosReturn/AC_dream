/*
 * @lc app=leetcode.cn id=502 lang=cpp
 *
 * [502] IPO
 */
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();

        int curr = 0;

        priority_queue<int, vector<int>, less<int> > que;
        vector< pair<int,int>> data;

        for(int i =0; i< n; i++)
            data.push_back({capital[i], profits[i]});
        
        sort(data.begin(), data.end());

        for(int i =0; i < k; i++)
        {
            while(curr < n && data[curr].first <= w)
            {
                que.push(data[curr].second);
                curr++;
            }

            if(!que.empty())
            {
                w += que.top();
                que.pop();
            }
            else
                break;
        }
        return w;
    }
};
// @lc code=end

