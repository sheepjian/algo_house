###Chapter 3 Dynamic Programming

####Definition
In mathematics, computer science, economics and bioinformatics, [**dynamic programming**](http://en.wikipedia.org/wiki/Dynamic_programming) is a method for solving complex problems by breaking them down into simpler subproblems.


####Questions


1. *Longest Common Subsequence (LCS) problem*
   - Question: 
   
         Given two sequences, print the longest subsequence present in both of them.
   - Example:   
   
         LCS for input "ABCDGH" and "AEDFHR" is "ADH" of length 3   
         LCS for input "AGGTAB" and  "GXTXAYB" is "GTAB" of length 4  
         
   - A: see ./code/ch3.1.cpp

2. *Egg Dropping Puzzle*
   - Question: 
       
            Given x eggs, what is the minimum times of testing needed for the worst case of finding the "threshold" floor in an M-storey building. Let's call the threshold floor N. What this means is that the egg will not break dropped from any floor below floor N, but the egg will definitely break from any floor no less than N. You should treat all the eggs are exactly same.  
            
   - Example:  
    
         You want to find the threshold floor in a 100-storey building with only 2 eggs.
         Then the minimum times of testing for the worst case is 14
   - A: see ./code/ch3.2.cpp

======