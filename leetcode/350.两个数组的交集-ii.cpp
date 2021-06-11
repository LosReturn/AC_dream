/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersectByHash(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map <int, int> m;
        for (int num : nums1) {
            ++m[num];
        }
        vector<int> intersection;
        for (int num : nums2) {
            if (m.count(num)) {
                intersection.push_back(num);
                --m[num];
                if (m[num] == 0) {
                    m.erase(num);
                }
            }
        }
        return intersection;
    }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (vector<int>::iterator iter1=nums1.begin(), iter2=nums2.begin(); iter1!=nums1.end()&&iter2!=nums2.end();) {
            if (*iter1 == *iter2) {
                res.push_back(*iter1);
                iter1++;
                iter2++;
            } else if (*iter1 < *iter2) {
                iter1++;
            } else {
                iter2++;
            }
        }
        return res;
    }
};

// @lc code=end

