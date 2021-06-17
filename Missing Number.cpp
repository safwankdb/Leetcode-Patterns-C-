#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = 0;
        for (int i = 0; i < nums.size(); i++) a ^= i ^ nums[i];
        return a ^ nums.size();
    }
};