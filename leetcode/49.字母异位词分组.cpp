/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <vector>
#include <iostream>
#include <unordered_map>
#include <array>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<int, vector<string>> key_to_str;
        for (const auto& str : strs) {
            key_to_str[generateKey(str)].emplace_back(str);
        }
        vector<vector<string>> output;
        for (const auto& p : key_to_str) {
            output.emplace_back(p.second);
        }
        return output;
    }
    
private:
    int generateKey(const string& str) {
		// convert string to character count array
        array<int, 26> arr = {0};
        for (auto c : str) arr[c - 'a']++;
        
        // generate hash from int array
        const auto GOLDEN_RATIO = 0x9e3779b1;
        uint32_t seed = size(arr);
        for(auto i : arr) {
            seed ^= i + GOLDEN_RATIO + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
// @lc code=end

