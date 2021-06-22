# Leetcode Patterns C++

C++ solutions for the leetcode problem list [https://seanprashad.com/leetcode-patterns]()

## Hard

- #### Binary Tree Maximum Path Sum
    DFS on the tree, return the max sum including the root and one side. Calculate the sum of both sides within the function and track using global max.

- #### Word Seach II
    Make Trie from words and then DFS.

## Medium

- #### Coin Change
    Build a DP from bottom up. amount = 0 takes 0 coins, for all amounts, iterate over all coins and add them once. Skip if the current amount is unreachable. Sorting the coins may give slight speedup.

- #### Implement Trie (Prefix Tree)
    Straightforward if concept is known. [Playlist for understanding Tries](https://www.youtube.com/watch?v=6PX6wqDQE20&list=PLEJXowNB4kPyi859E6qGUs7jlpQehJndl)

- #### Target Sum
    Basic dfs is accepted, there is decent speedup with memoization. The optimal solution uses subset sum and should be studied [here](https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation).

- #### Generate Parentheses
    For n > 0, there will aalways be an opening bracket left most. If the expression inside the leftmost bracket and its complement has i pairs, there'll the n-i-1 pairs outside. Just use recursion to find these sets and take product.

- #### Linked List Cycle II
    - Use hashmap of pointers to nodes.
    - For O(1) space, mark visited on input.
    - If input is non mutable, then use 2 pointers to find intersection, then move the slow pointer and a new pointer from head together, they'll meet at start of cycle.

    - When the fast and slow pointers meet, the slow pointer has movec m steps = length of cycle. 

- #### Decode Ways
    Just use 2 dimensional DP. Keep track of carry.

- #### Word Search
    - Simple DFS / Backtracking algorithm. 
    - Can save space by marking visited notes inplace using special char instead of maintaing a boolean 2d array.

- #### Rotate Image
    - Transpose then Flip in place.
    - Can do it in almost half the operations by replacing values in circular order.

- #### K Closest Points to Origin
    Push all in a heap (priority_queue) and pop k elements. Note the details of overloading the comparator.

## Easy

- #### Invert Binary Tree
    Recursively swap left and right subtrees.

- #### Path Sum
    Simple recursion. Solve subproblems for both child trees.

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

## Concepts to Revise

- [ ] Segment Tree
- [ ] Fenwick Tree
- [ ] Quadtree
- [ ] Trie
- [ ] Monotonic Queue
- [ ] 0-1 BFS
- [ ] Union Find
