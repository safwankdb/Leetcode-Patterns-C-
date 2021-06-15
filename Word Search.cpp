#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool dfs(vector<vector<char>>& board, string& word, int x, int i, int j) {
        if (x == word.size()) return true;
        const int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (board[i][j] == '#') return false;

        static const int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
        int k;
        bool found = false;
        if (board[i][j] == word[x]) {
            char tmp = board[i][j];
            board[i][j] = '#';
            for (k = 0; k < 4; k++) {
                found |= dfs(board, word, x + 1, i + di[k], j + dj[k]);
                if (found) break;
            }
            board[i][j] = tmp;
        }
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size(), n = board[0].size();
        bool found = false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0]) {
                    found |= dfs(board, word, 0, i, j);
                    if (found) return true;
                }
        return found;
    }
};