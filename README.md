# LeetCode

Some interesting LeetCode programming questions

## Problem 44: Wildcard Matching

[The Problem](https://leetcode.com/problems/wildcard-matching/)

 1. Recognize a recursion solution [P44_Recursion.cpp](P44_Recursion.cpp)

    Similar to many problems involving a lot of decision making via back-tracking, string matching problems are usually solved using recursion.
    One way to view the problem is to try to reduce the problem by the length of the pattern, from the pattern string of length $n$ to a shorter pattern of length $n - 1$.
    Here, we make a generalization function `isMatch(s, i, p, j)` to match the substring of `s` starting from `i` till the end of `s` with the subpattern of `p` starting from `j`.

 2. Dynamic programming: [P44_DP.cpp](P44_DP.cpp)

    From the recursive solution, we find that the call `isMatch(_, _, _, j)` only depends on `isMatch(_, _, _, j + 1)`.
    This suggests us to construct the table `M[j][i] := isMatch(s, i, p, j)` row by row from row `j` = length of `p` down to row `j = 0` to cache the redundant computations.

 3. Further optimizations: [P44_DP_Opt.cpp](P44_DP_Opt.cpp)
     - We only need to keep track of two consecutive rows.
     - We can preprocess the pattern by merging consecutive `*` (not performed).
     - Add sentinels to avoid the range checking. Alternatively, reorder the second loop inside case `switch`.
