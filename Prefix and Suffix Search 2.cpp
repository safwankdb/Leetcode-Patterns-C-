#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    int index = -1;
    TrieNode* next[26][26];

    TrieNode() { fill_n(&next[0][0], 26 * 26, nullptr); }

    ~TrieNode() {
        for (auto node : next) delete &node;
    }

    void insert(string s, int index) {
        auto x = this;
        int n = s.size(), i1, i2;
        for (int i = 0; i < n; i++) {
            i1 = s[i] - 'a';
            i2 = s[n - i - 1] - 'a';
            if (x->next[i1][i2] == NULL) x->next[i1][i2] = new TrieNode();
            x = x->next[i1][i2];
        }
        x->index = index;
    }
};

class WordFilter {
    TrieNode root;

   public:
    WordFilter(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) root.insert(words[i], i);
    }

    int f(string prefix, string suffix) {
        auto x = &root;
        int np = prefix.size(), ns = suffix.size();
        for (int i = 0; i < min(np, ns); i++) {
            x = x->next[prefix[i] - 'a'][suffix[ns - i - 1] - 'a'];
            if (x == NULL) return -1;
        }

        queue<TrieNode*> Q;
        Q.push(x);

        for (int i = min(np, ns); i < np; i++) {
            int s = Q.size();
            for (int j = 0; j < s; j++) {
                auto x = Q.front();
                Q.pop();
                for (int k = 0; k < 26; k++) {
                    if (x->next[prefix[i] - 'a'][k] != NULL)
                        Q.push(x->next[prefix[i] - 'a'][k]);
                }
            }
        }

        for (int i = min(np, ns); i < ns; i++) {
            int s = Q.size();
            for (int j = 0; j < s; j++) {
                auto x = Q.front();
                Q.pop();
                for (int k = 0; k < 26; k++) {
                    if (x->next[k][suffix[ns - i - 1] - 'a'] != NULL)
                        Q.push(x->next[k][suffix[ns - i - 1] - 'a']);
                }
            }
        }

        int ans = -1;
        while (!Q.empty()) {
            int s = Q.size();
            for (int j = 0; j < s; j++) {
                auto x = Q.front();
                Q.pop();
                if (x->index != -1) ans = max(ans, x->index);
                for (int k = 0; k < 26; k++) {
                    for (int l = 0; l < 26; l++) {
                        if (x->next[k][l] != NULL) Q.push(x->next[k][l]);
                    }
                }
            }
        }
        return ans;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */