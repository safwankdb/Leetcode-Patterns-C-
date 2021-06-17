#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct Point {
        int x, y;
        Point(int a, int b) {
            x = a;
            y = b;
        }
        bool operator<(const Point& b) const {
            return (x * x + y * y) > (b.x * b.x + b.y * b.y);
        }
    };

   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point> P;
        for (auto p : points) P.push(Point(p[0], p[1]));
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            Point p = P.top();
            ans.push_back({p.x, p.y});
            P.pop();
        }
        return ans;
    }
};