#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < amount; i++) {
            if (dp[i] == INT_MAX) continue;
            for (int c : coins) {
                if (c > amount - i) continue;
                dp[i + c] = min(1 + dp[i], dp[i + c]);
            }
        }
        return (dp[amount] != INT_MAX) ? dp[amount] : -1;
    }
};