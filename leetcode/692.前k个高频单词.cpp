/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

#include <vector>
#include <queue>
#include <iostream>
#include <functional>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        // statics
        unordered_map<string, int> cnt;
        for (auto& word: words)
            cnt[word]++;

        //customer cmp
        std::function<bool(const pair<string, int>& a, const pair<string, int>& b)> 
            cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.second == b.second ? a.first < b.first : a.second > b.second;
            };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> que(cmp);

        for(auto& curr: cnt)
        {
            if(que.size() < k)
                que.push(curr);
            else
            {
                if(cmp(curr, que.top())){
                    que.pop();
                    que.push(curr);
                }
            }
        }
        
        vector<string> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = que.top().first;
            que.pop();
        }
        return ret;
    }
};
// @lc code=end

