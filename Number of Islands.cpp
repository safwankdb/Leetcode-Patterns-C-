#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    bool dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
        if (grid[i][j] == '0') return false;
        grid[i][j] = '0';
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (dfs(grid, i, j)) counter++;
        return counter;
    }
};