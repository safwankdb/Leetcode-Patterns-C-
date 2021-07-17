#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        const int n1 = a.size(), n2 = b.size();
        const int k = (n1 + n2) / 2 + 1, tot = n1 + n2;
        int lo = max(0, k - n2), hi = min(k, n1), x, y;
        while (lo < hi) {
            x = lo + (hi - lo + 1) / 2;
            y = k - x;
            if (a[x - 1] <= b[y])
                lo = x;
            else
                hi = x - 1;
        }
        x = lo;
        y = k - x;
        if (x == 0) {
            if (tot % 2)
                return b[y - 1];
            else
                return (b[y - 1] + b[y - 2]) / 2.0;
        } else if (y == 0) {
            if (tot % 2)
                return a[x - 1];
            else
                return (a[x - 1] + a[x - 2]) / 2.0;
        } else if (tot % 2) {
            return max(a[x - 1], b[y - 1]);
        } else {
            vector<int> tmp = {a[x - 1], b[y - 1]};
            if (x > 1) tmp.push_back(a[x - 2]);
            if (y > 1) tmp.push_back(b[y - 2]);
            sort(tmp.begin(), tmp.end(), greater<int>());
            return (tmp[0] + tmp[1]) / 2.0;
        }
    }
};