#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n - 1, mid = lo + (hi - lo + 1) / 2;
        while (lo < hi) {
            if (arr[mid] > arr[mid - 1])
                lo = mid;
            else
                hi = mid - 1;
            mid = lo + (hi - lo + 1) / 2;
        }
        return mid;
    }
};