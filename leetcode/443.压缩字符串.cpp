/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int left = 0, curr =0;
        for(int read = 0; read < n; read++)
        {
            if(read == n-1 || chars[read] != chars[read+1])
            {
                chars[curr++]=chars[read];
                int num = read - left + 1;
                if(num > 1)
                {
                    int anchor = curr;
                    while(num)
                    {
                        chars[curr++] = num%10 +'0';
                        num/=10;
                    }
                    reverse(&chars[anchor], &chars[curr]);
                }
                left = read+1;
            }
        }
        return curr;
    }
};
// @lc code=end

