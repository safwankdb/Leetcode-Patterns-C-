#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    struct TrieNode {
        bool isWord = false;
        TrieNode* children[26];
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = NULL;
        }
    };

    struct Trie {
        TrieNode* root = new TrieNode();

        void insert(string s) {
            TrieNode* x = root;
            int idx;
            for (char c : s) {
                idx = c - 'a';
                if (x->children[idx] == NULL) x->children[idx] = new TrieNode();
                x = x->children[idx];
            }
            x->isWord = true;
        }
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie T;
        for (string s : wordDict) T.insert(s);
        unordered_set<TrieNode*> S = {T.root}, next;
        int idx;
        for (char c : s) {
            next.clear();
            idx = c - 'a';
            for (TrieNode* t : S)
                if (t->children[idx] != NULL) {
                    next.insert(t->children[idx]);
                    if (t->children[idx]->isWord) next.insert(T.root);
                }
            S = next;
        }
        for (TrieNode* t : S)
            if (t->isWord) return true;
        return false;
    }
};