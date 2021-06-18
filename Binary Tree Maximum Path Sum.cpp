#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int dfs(TreeNode *x, int &ans) {
        if (x == NULL) return 0;
        int l = max(0, dfs(x->left, ans));
        int r = max(0, dfs(x->right, ans));
        ans = max(ans, l + r + x->val);
        return x->val + max(l, r);
    }

    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};