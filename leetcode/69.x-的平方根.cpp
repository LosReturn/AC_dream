/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        unsigned long x0 = x >> 1;				// Initial estimate

	// Sanity check
        if ( x0 )
        {
            unsigned long x1 = ( x0 + x / x0 ) >> 1;	// Update
            
            while ( x1 < x0 )				// This also checks for cycle
            {
                x0 = x1;
                x1 = ( x0 + x / x0 ) >> 1;
            }
            
            return x0;
        }
        else
        {
            return x;
        }
    }
};
// @lc code=end

