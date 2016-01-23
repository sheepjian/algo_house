Longest Increasing Path in a Matrix
====================

### Note:

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

### Example:

**Example 1:**

```
nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
```

Return 4

The longest increasing path is [1, 2, 6, 9].

**Example 2:**
```
nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
```

Return 4

The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

### Answer:

The first impression about this question contains following two points:

* The lower bound could be O(mn), m is the number of rows, n is the number of columns;
* It is similar to find the longest increasing substring of a string.

Note: substring is different from subsequence; subsequence is not necessarily contiguous.
Finding the longest increasing substring could be solved by DP in O(n^2), or [patience sorting](https://en.wikipedia.org/wiki/Longest_increasing_subsequence) in O(nlogn).   

For any increasing substring, the start should be the smallest number , and the end will be the largest number.

For a string str[1:n], A[n]=A[n-1]+1 or 1 (depend on whether str[n]>str[n-1] or not), 
where denote the length of the longest increasing substring ending with str[n]. 
The result will be max(A[i]). Time complexity is O(n).

For a matrix mat[1:m, 1:n], the situation in this question is little different. 
There is no commonly accepted *start* and *end*, since it allows node move to four directions without breaking the boundary. (For string, the start always sit on the left side of the end.)

For example, given any two entries a and b.  
In the string case, if a is on the left side of b, and b is not larger than a, 
we can immediately there is no increasing substring. Then we can find the recursive formula very easily.
However, in the matrix case, no matter what is the order between a and b, there may still exist solution.
There is no simple explicit recursive formula between a and its neighbors.

But we still get something during this thinking process. That is, for an entry a, if all neighbors are no less than a, a is the smallest point in the local area, let us call it trough. Same for an entry b, if all neighbors are no larger than b, b is the largest point in the local area, let us call it peak. 

Now it is easy to find a lemma, for any valid increasing substring in the matrix, the start must be a through, the end must be a peak.

What does this remind you?

Map, indegree, outdegree, topological sorting, DFS...  

Now we get out the trap of DP. Treat the matrix as a map. Travelle through all unvisited entries by DFS, and record the depth of each visited entry by the maximum of its visited neighbor's depth plus 1. In the end, the largest record will be the result you want.

The time complexity is same as we imagine in the beginning, O(mn).

