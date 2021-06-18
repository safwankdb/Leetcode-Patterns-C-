#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int f(string &s, int i, int carry, int dp[][3]) {
        // Return no of ways to decode starting from ith letter in string
        if (carry > 2) {
            return 0;

        } else if (dp[i][carry] != -1) {
            return dp[i][carry];

        } else if (i == s.size()) {
            dp[i][carry] = (carry == 0) ? 1 : 0;
        } else if (carry == 0) {
            if (s[i] == '0')
                dp[i][0] = 0;
            else
                dp[i][0] = f(s, i + 1, 0, dp) + f(s, i + 1, s[i] - '0', dp);
        } else if (carry == 1) {
            dp[i][1] = f(s, i + 1, 0, dp);
        } else if (carry == 2) {
            if (s[i] > '6')
                dp[i][2] = 0;
            else
                dp[i][2] = f(s, i + 1, 0, dp);
        }
        return dp[i][carry];
    }

    int numDecodings(string s) {
        int dp[s.size() + 1][3];
        for (int i = 0; i < s.size() + 1; i++) {
            dp[i][0] = -1;
            dp[i][1] = -1;
            dp[i][2] = -1;
        }
        return f(s, 0, 0, dp);
    }
};