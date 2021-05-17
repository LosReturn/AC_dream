/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        std::vector<int>::iterator __first = nums.begin();
        std::vector<int>::iterator __last = nums.end();
        if (__first == __last)   //若区间为空，返回false
            return;

        std::vector<int>::iterator __i = __first;
        ++__i;
        if (__i == __last)      
        return;
        __i = __last;
        --__i;
 
        for(;;) {
            std::vector<int>::iterator __ii = __i;
            --__i;
            if (*__i < *__ii) {                //找到了这样一组i,ii
                std::vector<int>::iterator __j = __last;
                while (!(*__i < *--__j)){}
                iter_swap(__i, __j);             //交换i,j
                reverse(__ii, __last);           //将[ii,last)内的元素全部逆转
                return;
            }
            if (__i == __first) {        //已经到最前面了，，也就是说当前的序列已经是全排列的最后一个排列了
                reverse(__first, __last);  //将整个序列颠倒
                return;
            }
        }
    }
};
// @lc code=end

