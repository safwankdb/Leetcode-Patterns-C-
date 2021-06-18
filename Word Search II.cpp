#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    struct TrieNode {
        bool isWord = false, counted = false;
        TrieNode* children[26];
        string word;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = NULL;
        }
    };

    struct Trie {
        TrieNode* root;
        Trie() { root = new TrieNode(); }

        void insert(string s) {
            TrieNode* x = root;
            int idx;
            for (char c : s) {
                idx = c - 'a';
                if (x->children[idx] == NULL) {
                    x->children[idx] = new TrieNode();
                    x->children[idx]->word = x->word + c;
                }
                x = x->children[idx];
            }
            x->isWord = true;
        }
    };

    void dfs(int x, int y, vector<vector<char>>& board, TrieNode* root,
             vector<string>& ans) {
        int m = board.size(), n = board[0].size();
        if (board[x][y] == '#') return;

        root = root->children[board[x][y] - 'a'];
        if (root == NULL) return;

        if (root->isWord && !root->counted) {
            ans.push_back(root->word);
            root->counted = true;
        }
        const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
        char temp = board[x][y];
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) {
            int p = x + dx[i], q = y + dy[i];
            if (p < 0 || p >= m || q < 0 || q >= n) continue;
            dfs(p, q, board, root, ans);
        }
        board[x][y] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        Trie* T = new Trie();
        for (string word : words) T->insert(word);

        vector<string> ans;
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, board, T->root, ans);
            }
        }

        return ans;
    }
};