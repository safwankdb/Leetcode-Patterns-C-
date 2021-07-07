#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int currSum = INT_MIN, maxSum = INT_MIN;
        for (int& i : nums) {
            currSum = max(currSum, 0);
            currSum += i;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};