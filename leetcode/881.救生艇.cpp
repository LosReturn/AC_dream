/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int cnt = 0;
        int l = 0, r = people.size()-1;
        while( l<=r )
        {
            if( (people[r] + people[l]) <= limit)
                l++;
            cnt++;
            r--;     
        }
        return cnt;
    }
};
// @lc code=end

