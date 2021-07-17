#include <bits/stdc++.h>

using namespace std;

class Solution {
    int getBoard(vector<vector<int>>& board, int i) {
        int n = board.size();
        i--;
        int r = (n - 1) - (i / n);
        int c = i  % n;
        if (r % 2 == n % 2) c = n - 1 - c;
        return board[r][c];
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int path[n*n + 1];
        fill_n(path, n*n + 1, -1);
        
        queue<int> Q;
        Q.push(1);
        int pathLength = 0, size, i, i_;
        while(!Q.empty() && path[n*n] == -1) {
            size = Q.size();
            for (int s = 0; s < size; s++) {
                i = Q.front(); Q.pop();
                i_ = getBoard(board, i);
                if (i_ != -1) i = i_;
                if (path[i] != -1) continue;
                path[i] = pathLength;
                for (int j = 1; j <= 6; j++) {
                    if (i + j > n*n) break;
                    Q.push(i + j);
                }
            }
            pathLength++;
        }
        return path[n*n];
    }
};