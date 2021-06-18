# Leetcode Patterns C++

C++ solutions for the leetcode problem list [https://seanprashad.com/leetcode-patterns]()

## Hard

- #### Binary Tree Maximum Path Sum
    DFS on the tree, return the max sum including the root and one side. Calculate the sum of both sides within the function and track using global max.


## Medium

- #### Decode Ways
    Just use 2 dimensional DP. Keep track of carry.

- #### Word Search
    Simple DFS / Backtracking algorithm. Can save space by marking visited notes inplace using special char instead of maintaing a boolean 2d array.

- #### Rotate Image
    Transpose then Flip. Can do it in almost half the operations by replacing values in circular order.

- #### K Closest Points to Origin
    Push all in a heap (priority_queue) and pop k elements. Note the details of overloading the comparator.

## Easy

- #### Contains Duplicate
    Use hash table (unordered_set in C++).


- #### Missing Number
    Use property of XOR.

- #### Climbing Stairs
    Find the nth fibonacci number.

- #### Longest Word in Dictionary
    Make a Trie and add all the words and the string made till that word too. Perform dfs for the longest string under any TrieNode with all isWord values being true. Call dfs(root).

- #### Single Number
    Use property of XOR.

- #### Minimum Depth of Binary Tree
    Easy recursion. Edge case of NULL root node.


