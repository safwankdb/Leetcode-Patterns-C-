#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int lo = 0, hi = n - 1, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (mid == 0 && nums[mid] > nums[mid+1]) return 0;
            else if (mid == n-1 && nums[n-2] < nums[n-1]) return n-1;
            else if (nums[mid] > nums[mid+1])
                if (nums[mid] > nums[mid-1]) return mid;
                else hi = mid - 1;
            else lo = mid + 1;
        }
        return (lo + hi) / 2;
    }
};