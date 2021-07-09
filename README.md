# Leetcode Patterns C++

C++ solutions for the leetcode problem list [https://seanprashad.com/leetcode-patterns]() and some other good problems.

## Hard

#### Merge k Sorted Lists
- Make a heap of ListNode* with custom comparator.
- Keep popping from heap and if next node is present, push it in the heap. -> O(n log(k))

#### Cherry Pickup
- Problem is equivalent to 2 people walking from top left to bottom right.
- x1 + y1 = x2 + y2 always => we can use a 3D DP with states (x1, y1, x2).
- Count cherry only once if they both land at same place.
- Make sure all answers are being memoized (the -1 case when path is invalid).


#### Binary Tree Maximum Path Sum
- DFS on the tree, return the max sum including the root and one side. Calculate the sum of both sides within the function and track using global max.

#### Word Search II
- Make Trie from words and then DFS.

## Medium

#### Longest Consecutive Sequence
1. Use Union Find with path compression, if any neighbors are encountered, union them. Count the max size of a connected set. -> O(N * alpha(N)) (Not sure of compexity, need to confirm).
2. As in the leetcode dicussion, just walk each streak. Make a set from the array and count the max length of streak we can get starting from each element. If i-1 is in set for an elemnent i, dont count from i. -> O(n)

#### Kth Smallest Element in a Sorted Matrix
- For all the below methods : if using heap / set, work with tuple<int, int, int> of (value, row, column).
1. Add all elements to heap and pop k times -> O(n^2 + klog(n)) = O(n^2)
2. Maintain size of heap at k by adding and popping min element after each add. -> O(n^2)
3. For a value x, write countLessThan(x) which return number of elements less than x. It can be done in nlog(n) time by just binary search inside every row. Then binary search the value of x for which function returns countLessThan(x) = k. -> O(nlog(n)log(range(matrix)))
4. Use BFS. If there is a set S of possible elements for m'th position and let x_m be the m'th smallest element, the possible elements for m+1'th position would lie in (S \ {x_m}) U (Neighbors of x_m). Iterate until k, for each position pop the min element from a heap, update the frontier set. -> O(klog(k))

#### Sort List
- Just use recursive merge sort for O(log(n)) space. Use iterative for O(1).

#### Number of Islands
- Use DFS to check islands and increment the counter.

#### Reverse Linked List II
- Reverse from left node, keep a counter for number of reversals. special case when left = 1.

#### Sort Colors
- Count the elements and replace.

#### Jump Game
- Keep track of farthest reachable index from current index. Iterate as far as reachable. If last index is reachable, return true.

#### Word Break
- Use Trie to store dictionary. BFS to search.

#### Coin Change
- Build a DP from bottom up. amount = 0 takes 0 coins, for all amounts, iterate over all coins and add them once. Skip if the current amount is unreachable. Sorting the coins may give slight speedup.

#### Implement Trie (Prefix Tree)
- Straightforward if concept is known. [Playlist for understanding Tries](https://www.youtube.com/watch?v=6PX6wqDQE20&list=PLEJXowNB4kPyi859E6qGUs7jlpQehJndl)

#### Target Sum
- Basic dfs is accepted, there is decent speedup with memoization. The optimal solution uses subset sum and should be studied [here](https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation).

#### Generate Parentheses
- For n > 0, there will always be an opening bracket left most. If the expression inside the leftmost bracket and its complement has i pairs, there'll the n-i-1 pairs outside. Just use recursion to find these sets and take product.

#### Linked List Cycle II
- Use hashmap of pointers to nodes.
- For O(1) space, mark visited on input.
- If input is non mutable, then use 2 pointers to find intersection, then move the slow pointer and a new pointer from head together, they'll meet at start of cycle.
- When the fast and slow pointers meet, the slow pointer has movec m steps = length of cycle. 

- #### Decode Ways
    Just use 2 dimensional DP. Keep track of carry.

#### Word Search
- Simple DFS / Backtracking algorithm. 
- Can save space by marking visited notes inplace using special char instead of maintaing a boolean 2d array.

#### Rotate Image
- Transpose then Flip in place.
- Can do it in almost half the operations by replacing values in circular order.

#### K Closest Points to Origin
- Push all in a heap (priority_queue) and pop k elements. Note the details of overloading the comparator.

## Easy

#### Maximum Subarray
- Kadane's Algorithm.

#### Counting Bits
- ```dp[i] = (i % 2) + dp[i / 2];```

#### Reverse Linked List
- Iteratively reverse direction of each 'arrow'.

#### Invert Binary Tree
- Recursively swap left and right subtrees.

#### Path Sum
- Simple recursion. Solve subproblems for both child trees.

#### Contains Duplicate
- Use hash table (unordered_set in C++).


#### Missing Number
- Use property of XOR.

#### Climbing Stairs
- Find the nth fibonacci number.

#### Longest Word in Dictionary
- Make a Trie and add all the words and the string made till that word too. Perform dfs for the longest string under any TrieNode with all isWord values being true. Call dfs(root).

#### Single Number
- Use property of XOR.

#### Minimum Depth of Binary Tree
- Easy recursion. Edge case of NULL root node.
