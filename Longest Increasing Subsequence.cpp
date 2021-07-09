#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);
        int ans = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j]) LIS[i] = max(LIS[i], 1 + LIS[j]);
            ans = max(ans, LIS[i]);
        }
        return ans;
    }
};