#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> buildArrayDirect(vector<int>& nums) {
        
        vector<int> ret;
        for(auto num: nums)
        {
            ret.push_back(nums[num]);
        }

        return ret;
    }

    // sum a << bit_len(b) + b; a = sum >> bit_len(b); 
    vector<int> buildArray(vector<int>& nums) {

        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            nums[i] += 1000*( nums[nums[i]] % 1000);
        }

        for( int i = 0; i < size; i++)
            nums[i] /= 1000;

        return nums;
    }
};
// @lc code=end