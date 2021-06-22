#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int counts[] = {0, 0, 0};
        for (int i : nums) counts[i]++;
        int i = 0;
        for (; i < counts[0]; i++) nums[i] = 0;
        for (int j = 0; j < counts[1]; j++) {
            nums[i] = 1;
            i++;
        }
        for (int j = 0; j < counts[2]; j++) {
            nums[i] = 2;
            i++;
        }
    }
};