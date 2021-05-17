/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        int curr = 0;
        back_trace(ret, nums, curr);
        return ret;
    }

    void back_trace(vector<vector<int>>& ret, vector<int>& nums, int curr)
    {
        if(curr == nums.size())
        {
            ret.emplace_back(nums);
            return;
        }

        for(int i =curr; i < nums.size(); i++)
        {
            swap(nums[curr],nums[i]);
            back_trace(ret, nums, curr+1);
            swap(nums[curr],nums[i]);
        }

    }
/*
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> vec;
        vector<bool> choosen(nums.size(),0);

        dfs(ret, vec, choosen, nums);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int>& vec, vector<bool>& choosen, vector<int>& nums)
    {
        if(vec.size()==nums.size())
        {
            ret.emplace_back(vec);
            return;
        }

        for(int i =0; i < nums.size(); i++)
        {
            if(choosen[i])
                continue;
            
            vec.push_back(nums[i]);
            choosen[i] = 1;

            dfs(ret, vec, choosen, nums);

            vec.pop_back();
            choosen[i] = 0;
        }
    }
*/
};
// @lc code=end

