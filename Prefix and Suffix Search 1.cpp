#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    int index = -1;
    string word;
    TrieNode *next[26];

    TrieNode() { fill(next, next + 26, (TrieNode *)NULL); }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) delete next[i];
    }

    void insert(string s, int index) {
        auto x = this;
        for (char &c : s) {
            int i = c - 'a';
            if (x->next[i] == NULL) x->next[i] = new TrieNode();
            x = x->next[i];
        }
        x->index = index;
        x->word = s;
    }
};

class WordFilter {
    TrieNode root;

   public:
    WordFilter(vector<string> &words) {
        for (int i = 0; i < words.size(); i++) root.insert(words[i], i);
    }

    int f(string prefix, string suffix) {
        set<TrieNode *> prefixMatch;
        auto x = &root;
        for (char &c : prefix) {
            x = x->next[c - 'a'];
            if (x == NULL) return -1;
        }
        queue<TrieNode *> Q;
        Q.push(x);
        int size;
        while (!Q.empty()) {
            size = Q.size();
            for (int i = 0; i < size; i++) {
                x = Q.front();
                Q.pop();
                if (x->index != -1) prefixMatch.insert(x);
                for (int j = 0; j < 26; j++) {
                    if (x->next[j] != NULL) Q.push(x->next[j]);
                }
            }
        }
        int maxIndex = -1, s = suffix.size(), n;
        bool flag;
        for (auto x : prefixMatch) {
            n = x->word.size();
            if (n < s || x->index < maxIndex) continue;
            flag = true;
            for (int i = 0; i < s; i++) {
                if (suffix[s - i - 1] != x->word[n - i - 1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) maxIndex = max(maxIndex, x->index);
        }
        return maxIndex;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */