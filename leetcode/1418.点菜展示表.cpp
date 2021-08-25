/*
 * @lc app=leetcode.cn id=1418 lang=cpp
 *
 * [1418] 点菜展示表
 */
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> displayTableHASH(vector<vector<string>>& orders) {
        
        unordered_set<string> menu;
        unordered_map<int, unordered_map<string, int> > foods;
        string food_name;
        for(auto& order: orders)
        {
            menu.insert(order[2]);
            int id = stoi(order[1]);
            foods[id][order[2]]++;
        }
        
        int n = menu.size();
        vector<string> title;
        for(auto& str: menu)
            title.push_back(str);
        
        sort(title.begin(), title.end());

        unordered_map<int, unordered_map<string, int>>::iterator it;
        vector<int> ids;

        for( it = foods.begin(); it != foods.end(); it++)
            ids.push_back(it->first);
        int m = ids.size();
        sort(ids.begin(), ids.end());

        vector<vector<string> > ret(m+1, vector<string>(n+1, ""));
        ret[0][0] = "Table";
        copy(title.begin(), title.end(), ret[0].begin()+1);

        for( int i = 1; i<m+1; i++)
        {
            ret[i][0] = to_string(ids[i-1]);
            unordered_map<string, int>& item = foods[ids[i-1]];
            for(int j = 1; j < n+1; j++)
            {
                ret[i][j] = to_string(item[title[j-1]]);
            }
        }
        return ret;
    }

    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        
        set<string> title;
        map<int, unordered_map<string, int> > foods;
        
        for(auto& order: orders)
        {
            title.insert(order[2]);
            int id = stoi(order[1]);
            foods[id][order[2]]++;
        }
        
        int m = foods.size();
        int n = title.size();

        vector<vector<string> > ret(m+1, vector<string>(n+1, "0"));
        ret[0][0] = "Table";        
        //copy(title.begin(), title.end(), ret[0].begin()+1);

        unordered_map<string, int> idx;
        set<string>::iterator it1 = title.begin();
        for(int i = 1; i < n+1; i++)
        {
            ret[0][i] = *it1;
            idx[*it1] = i;
            it1++;
        }

        map<int, unordered_map<string, int> >::iterator it2 = foods.begin();
        for( int i = 1; i<m+1; i++)
        {
            ret[i][0] = to_string(it2->first);
            for(auto& item: it2->second)
            {
                ret[i][idx[item.first]] = to_string(item.second);
            }
            it2++;
        }
        return ret;
    }

};
// @lc code=end

