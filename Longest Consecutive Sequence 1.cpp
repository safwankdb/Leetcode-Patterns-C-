#include <bits/stdc++.h>

using namespace std;

class Solution {
    
    struct UnionFind {
        unordered_map<int, int> parents;

        int Find(int a) {
            if (parents.count(a) == 0) return INT_MIN;
            else if (parents[a] == a) return a;
            else parents[a] = Find(parents[a]);
            return parents[a];
        }
        
        void put(int a) {
            if (parents.count(a) > 0) return;
            else parents[a] = a;
        }
        
        int Union(int a, int b) {
            int p1 = Find(a), p2 = Find(b);
            if (p1 == INT_MIN || p2 == INT_MIN) return INT_MIN;
            parents[p2] = p1;
            return p1;
        }
    };
    
public:
    int longestConsecutive(vector<int>& nums) {
        UnionFind UF;
        for (int i : nums) {
            UF.put(i);
            UF.Union(i, i-1);
            UF.Union(i, i+1);
        }
        int ans = 0;
        unordered_map<int, int> freq;
        for (auto [k, v] : UF.parents) {
            v = UF.Find(v);
            if (freq.count(v) == 0) freq[v] = 1;
            else freq[v]++;
            ans = max(ans, freq[v]);
        }
        return ans;
    }
};