#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) dp[i] = (i % 2) + dp[i / 2];
        return dp;
    }
};