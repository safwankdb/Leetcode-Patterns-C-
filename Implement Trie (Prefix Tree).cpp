#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    bool isWord = false;
    TrieNode* children[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = NULL;
    }
};

class Trie {
   public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int index;
        TrieNode* x = root;
        for (char w : word) {
            index = w - 'a';
            if (x->children[index] == NULL) x->children[index] = new TrieNode();
            x = x->children[index];
        }
        x->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int index;
        TrieNode* x = root;
        for (char w : word) {
            index = w - 'a';
            if (x->children[index] == NULL) return false;
            x = x->children[index];
        }
        return x->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        int index;
        TrieNode* x = root;
        for (char w : prefix) {
            index = w - 'a';
            if (x->children[index] == NULL) return false;
            x = x->children[index];
        }
        return true;
    }
};