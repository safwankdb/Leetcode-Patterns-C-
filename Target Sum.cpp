#include <bits/stdc++.h>

using namespace std;
class Solution {
   public:
    typedef map<pair<int, int>, int> map;
    int dfs(vector<int> &nums, map &memo, int t, int i) {
        if (memo.find({i, t}) != memo.end()) {
            return memo[{i, t}];
        } else if (i == nums.size()) {
            memo[{i, t}] = (t == 0) ? 1 : 0;
        } else {
            int plus = dfs(nums, memo, t - nums[i], i + 1);
            int minus = dfs(nums, memo, t + nums[i], i + 1);
            memo[{i, t}] = plus + minus;
        }
        return memo[{i, t}];
    }

    int findTargetSumWays(vector<int> &nums, int target) {
        map memo;
        return dfs(nums, memo, target, 0);
    }
};