/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    //naive
    string findLongestWord(string s, vector<string>& dictionary) {
        
        sort(dictionary.rbegin(), dictionary.rend(), [](auto&& a, auto&& b){return a.size() < b.size() || a.size() == b.size() && a > b;});        
        int n =  s.size();
        
        vector<vector<int>> next(n, vector<int>(26, -1));
        for(int i = n-2; i > 0; i--)
        {
            for(int j = 0; j < 26; j++)
                next[i][j] = s[i] == (j + 'a') ? i: next[i+1][j];
        }

        for(auto str: dictionary)
        {   
            int i =0, j =0;
            while(i < str.size() && j < s.size())
            {
                
                if(str[i] == s[j++])
                    i++;
            }
            if( i == str.size())
                return str;
        }
        return "";
    }
};
// @lc code=end

