#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            auto A = generateParenthesis(i);
            auto B = generateParenthesis(n - i - 1);
            for (string a : A)
                for (string b : B) ans.push_back('(' + a + ')' + b);
        }
        return ans;
    }
};