/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int dfs(unordered_map< int, Employee*>& mmap, int id )
    {
        Employee* pEmployee = mmap[id];
        int ret = pEmployee->importance;
        for(auto id: pEmployee->subordinates)
        {
            ret += dfs(mmap, id);
        }
        return ret;
    }

    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map< int, Employee*> mmap;

        for( auto& emp: employees)
        {
            mmap[emp->id] = emp;
        }

        return dfs( mmap,id);
    }
};
// @lc code=end

