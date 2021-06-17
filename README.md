# Leetcode Patterns C++

C++ solutions for the leetcode problem list [https://seanprashad.com/leetcode-patterns]()

- #### Word Search
    Simple DFS / Backtracking algorithm. Can save space by marking visited notes inplace using special char instead of maintaing a boolean 2d array.

- #### Contains Duplicate
    Use hash table (unordered_set in C++).


- #### Missing Number
    Use property of XOR.

- #### Rotate Image
    Transpose then Flip. Can do it in almost half the operations by replacing values in circular order.

- #### Climbing Stairs
    Find the nth fibonacci number.

- #### Longest Word in Dictionary
    Make a Trie and add all the words and the string made till that word too. Perform dfs for the longest string under any TrieNode with all isWord values being true. Call dfs(root).
