/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    string join_str(vector<string>& words, int left, int right, string sep)
    {
        string str = words[left];
        for(int i = left+1; i < right; i++)
            str += sep + words[i];
        return str;
    }

    string gen_blk(int len)
    {
        return string(len,' ');
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ret;

        int curr = 0;

        while(curr < n)
        {
            int head = curr;
            int sums = 0;
            
            while(curr<n && sums + words[curr].length() + curr - head <= maxWidth)
            {
                sums += words[curr++].length();
            }

            if(curr == n)
            {
                string str = join_str(words, head, curr, " ");
                ret.push_back( str + gen_blk( maxWidth - str.length()));
                return ret;
            }

            int numWords = curr - head;
            int numBlk = maxWidth - sums;

            if(numWords == 1)
            {
                ret.push_back(words[head] + gen_blk(numBlk));
                continue;
            }

            int avgBlkSep = numBlk / (numWords-1);
            int cnt = numBlk %(numWords-1);

            string str_l = join_str(words, head, cnt + head + 1, gen_blk(avgBlkSep+1));
            string str_r = join_str(words, cnt + head + 1, curr, gen_blk( avgBlkSep));
            ret.push_back(str_l + gen_blk(avgBlkSep) + str_r);
        }
        return ret;
    }
};
// @lc code=end

