Count of Range Sum
====================

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

### Note:
A naive algorithm of O(n^2) is trivial. You MUST do better than that.

### Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

### Answer:

**How to think?**

Let nums = [a_i,...,a_n]

Take s(i:j) (1<=i<=j<=n) as the sum from a_i to a_j consecutively

Because the time complexity should be less than O(n^2),
you can not list all the combinations of s(i:j).
You need to find a smart way to dervie s(i:j) first.

Draw a picture, you will find that once you have all the suffix array sum T[i],
you can find all s(i:j) = T[i] - T[j]. Here 1<=i<=n, i<j, 2<=j<=n+1.

**First Try:**

```
T[1:n+1] = 0;
For i from n to 1
    T[i] = T[i+1] + nums[i]
    For j from n+1 to i+1
        check whether s(i:j) = T[i] - T[j] fall into the range [lower, upper]
```

The complexity of above pseudo code is O(n^2), not works!

**Final Solution:**

The complexity comes from that you need to iterate through all the number T[j] after T[i]
and determine whether T[j]<T[i]-lower and T[i]-upper<T[j]. 

Make the lower=0. Does it remind you of any similar question? Aha, that's it, [count-of-smaller-numbers-after-self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

The only difference is that you need to count not only  the numbers after T[i] which
are smaller than some threshold, but also the numbers after T[i] which are larger
than some threshold. It is acceptable but annoying, because of wasting memory. 

A small trick here: given an array of numbers, to find how many numbers fall in a range [lower, upper], 
you can find how many numbers are smaller than upper+1, and how many numbers are smaller than lower.
The difference will be the answer.

Enjoy it!





