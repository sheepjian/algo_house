Count of Smaller Numbers After Self
====================
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

### Example:

```
Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0].
```

### Answer:

**First Try**
Naive case is that you can use two loops to find the answer, 
the time complexity will be O(n^2).

Obviously it won't be accepted by OJ.

**Idea**

Think about two numbers, nums[i] and nums[j] when 1<=i<j<=n.
Record the results in the array res[1:n].
If nums[i]>=num[j], then res[i]>=res[j].

It shows the idea that we can utilize the suffix results to save the searching
operation. But for above case, we still may miss some number nums[k], i<k<=n, k!=j 
that is nums[j]<=nums[k]<=nums[i]. 
To find all these number, the complexity is the same as our navie solution.

Therefore, we need a data structure to organize the previous results  
and guranttee that no nums[k] exist 
such that nums[j]<=nums[k]<=nums[i], i<k<=n, k!=j. (**The root of the problem!**)
Then it is easy to know nums[j] should be largest number of nums[i:j] 
such that nums[j]<=nums[i]. Then res[i] = res[j]+(1/0). 
And you need to **quickly** find nums[j]. 

Note: the lower bound of comparison based searching algorithm will be log(n), 
that is binary search.

Go through all data structure: stack, list, !sorted array!... !Binary Search Tree!

**Binary Search Tree**

For nums[i], to find res[i], we can build a BST by using nums[i+1:n]. 
The result res[j] of num[j] is namely the number of nodes in the left subtree of node j. 
When we insert nums[i] into the BST, we can sum all the left part
when nums[i] is moving right. nums[i] will be a new leaf of the BST after the insertion
operation is completed. Notice that you may need to handle the duplicated numbers.

The complexity now becomes O(nlog(n)).




