#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = greater<tuple<int, int, int>>();
        vector<tuple<int, int, int>> heap;
        int counter = 0, n = matrix.size(), ans;
        bool visited[n][n];
        fill_n(&visited[0][0], n * n, false);
        heap.reserve(2 * k + 1);
        heap.push_back({matrix[0][0], 0, 0});
        int dr[] = {0, 1}, dc[] ={1, 0};
        while (counter < k) {
            pop_heap(heap.begin(), heap.end(), cmp);
            auto [x, r, c] = heap.back();
            heap.pop_back();
            ans = x;
            counter++;
            for (int i = 0; i < 2; i++) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr < n && nc < n) {
                    if (!visited[nr][nc]) {
                        heap.push_back({matrix[nr][nc], nr, nc});
                        push_heap(heap.begin(), heap.end(), cmp);
                        visited[nr][nc] = true;
                    }
                }
            }
        }
        return ans;
    }
};