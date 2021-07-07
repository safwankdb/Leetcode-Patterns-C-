#include <bits/stdc++.h>

using namespace std;

class Solution {
    int dp[50][50][50];

    int dfs(vector<vector<int>>& grid, int x1, int y1, int x2) {
        const int y2 = x1 + y1 - x2, n = grid.size();
        if (x1 == n || y1 == n || x2 == n || y2 == n) return -1;
        else if (grid[x1][y1] == -1 || grid[x2][y2] == -1) return -1;
        else if (dp[x1][y1][x2] != INT_MIN) return dp[x1][y1][x2];
        else if (x1 == n - 1 && y1 == n - 1) return grid[n - 1][n - 1];
        int ans = -1, cherries = grid[x1][y1] + grid[x2][y2] * (x1 != x2);
        int dx1[] = {1, 1, 0, 0}, dy1[] = {0, 0, 1, 1}, dx2[] = {1, 0, 0, 1};
        for (int i = 0; i < 4; i++)
            ans = max(ans, dfs(grid, x1 + dx1[i], y1 + dy1[i], x2 + dx2[i]));
        if (ans == -1) dp[x1][y1][x2] = -1;
        else dp[x1][y1][x2] = ans + cherries;
        return dp[x1][y1][x2];
    }

   public:
    int cherryPickup(vector<vector<int>>& grid) {
        fill_n(&dp[0][0][0], 50 * 50 * 50, INT_MIN);
        return max(dfs(grid, 0, 0, 0), 0);
    }
};