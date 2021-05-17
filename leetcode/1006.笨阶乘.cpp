/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int clumsy(int N) {
        stack<int> eval({N});
        int sum=0, idx=0;
        N--;
        while(N>0)
        {
            switch (idx)
            {
            case 0:
                eval.top()*=N;
                break;
            case 1:
                eval.top()/=N;
                break;
            case 2:
                eval.push(N);
                break;
            case 3:
                eval.push(-N);
                break;
            }
            idx = (idx+1)%4;
            N--;
        }

        while(!eval.empty())
        {
            sum+=eval.top();
            eval.pop();
        }
        return sum;
    }
};
// @lc code=end

