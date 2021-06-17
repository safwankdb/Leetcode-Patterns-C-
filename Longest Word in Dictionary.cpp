#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    struct TrieNode {
        TrieNode* children[26];
        bool isWord = false;
        string word;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = NULL;
        }
    };

    struct Trie {
        TrieNode* root = new TrieNode();

        void add(string s) {
            TrieNode* x = root;
            int i;
            for (char c : s) {
                i = c - 'a';
                if (x->children[i] == NULL) {
                    x->children[i] = new TrieNode();
                    x->children[i]->word = x->word + c;
                }
                x = x->children[i];
            }
            x->isWord = true;
        }
    };

    string dfs(TrieNode* root) {
        string s, ans;
        for (int i = 0; i < 26; i++) {
            if (root->children[i] == NULL) continue;
            if (!root->children[i]->isWord) continue;
            s = dfs(root->children[i]);
            if (s.size() > ans.size()) ans = s;
        }
        return ans.size() ? ans : root->word;
    }

    string longestWord(vector<string>& words) {
        Trie T;
        for (string s : words) T.add(s);
        return dfs(T.root);
    }
};
