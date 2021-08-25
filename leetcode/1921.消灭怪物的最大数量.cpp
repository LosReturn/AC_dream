#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {

        vector<int> que;
        int sz = dist.size();

        for(int i = 0; i < sz; i++)
        {
            que.push_back( (dist[i] - 1) / speed[i] );
        }

        sort(que.begin(), que.end());

        for(int i = 0; i < sz; i++)
        {
            if(que[i] < i)
                return i;
        }
        return sz;
    }
};