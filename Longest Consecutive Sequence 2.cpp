#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> S(nums.begin(), nums.end());
        int ans = 0;
        for (int i : S) {
            if (S.find(i - 1) != S.end()) continue;
            int j = i + 1;
            while (S.find(j) != S.end()) j++;
            ans = max(ans, j - i);
        }
        return ans;
    }
};
