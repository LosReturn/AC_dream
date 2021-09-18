/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
#include < string >
#include < iostream >
#include < vector >
using namespace std;

// @lc code=start

class Trie{
public:
    Trie* next[26];
    std::string str;
    int cnt;

    Trie(): next{nullptr}, cnt(0)
    {
        str.clear();
    }

    void insert(const string& s)
    {
        Trie* p = this;
        for(char ch : s)
            p = p->next[ch-'a'] = (p->next[ch-'a'] ? p->next[ch-'a'] : (p->cnt++, new Trie));
        p->str = s;
    }

    void remove(char ch)
    {
        next[ch - 'a'] = nullptr;
        cnt--;
    }

    bool isNode() const
    {
        return !str.empty();
    }
};

class Solution {

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    Trie tree;
    vector<string> ret;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ret.clear();
        for(auto&& s: words)
            tree.insert(s);
        int m = board.size(), n = board[0].size();


        function<void(int, int, Trie*)> dfs = [&](int x, int y, Trie* tree)
        {
            Trie* head = tree->next[ board[x][y] - 'a' ];
            if( head == nullptr )
                return ;

            if( head->isNode()) {
                ret.emplace_back(move(head->str));
            }
            char save = 0;

            swap(save , board[x][y]);
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if( nx >=0 && nx < m && ny >=0 && ny < n && board[nx][ny] )
                    dfs(nx, ny, head);
            }

            swap(save, board[x][y]);

            if(head->cnt == 0)
                head->remove(board[x][y]);
        };

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dfs(i, j, &tree);
        return ret;
    }
};
// @lc code=end

