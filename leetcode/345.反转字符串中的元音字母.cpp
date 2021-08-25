/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        
        auto InVowels = [vowels = "aeiouAEIOU"s](char ch)
        {
            return vowels.find(ch) != std::string::npos;
        };

        int n = s.size();
        int l = 0; int r = n-1;
        
        while(l<r)
        {
            while (l < n && !InVowels(s[l])) 
                    ++l;
            while (r > 0 && !InVowels(s[r])) 
                    --r;
            if( l < r)
            {
                swap(s[l], s[r]);
                ++l, --r;
            }
        }
        return s;
    }
};
// @lc code=end

