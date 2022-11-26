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

## Problem 121: Best Time to Buy and Sell Stock

[This easy problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) is an example of the Greedy approach. Basically, we want to compute
$$max \{ prices[j] - prices[i] : 0 \leq i < j < n \} = max \{ K(j) : 1 \leq j < n \}$$
where
$$K(j) = max \{ prices[j] - prices[i] : 0 \leq i < j \}$$
gives the maximum profit if we _sell_ the stock on day `j`.

We have
$$K(j) = prices[j] - min \{ prices[i] : 0 \leq i < j \}$$
or intuitively, if we _sell_ the stock on day `j` then we get the maximum profit if we purchase it when it was at the _lowest_ price before day `j` (this is where the greedy approach is).

So we have [an `O(n)` solution](P121.cpp) by letting `j` runs from `1` to `n`, keeping track of the minimum prices prior to `j` to compute `K(j)` and find the minimum of those numbers.

The solution to this problem gives an `O(n)` solution to Problem 53 below.

## Problem 53: Maximum Subarray

[This problem](https://leetcode.com/problems/maximum-subarray/) can be turned into Problem 121 using the common technique of _prefix sum_ a.k.a. the Fundamental Theorem of Calculus.

For an array `a`, we are interested in the subarray sums
$$S_a(i, j) = a[i] + a[i+1] + ... + a[j-1]$$
for all possible range $0 \leq i < j \leq n$.
To avoid doing the $j - i$ additions everytime we need such a sum, we could store the numbers $S_a(0, k)$ for all $0 \leq k \leq n$ and then a single subtraction suffices, namely $S_a(0, j) - S_a(0, i)$.
These numbers are the prefixed sum for the array `a`.

Now we could recognize that the problem is to find the indices `i` and `j` such that the difference $S_a(0, j) - S_a(0, i)$ is maximum and this is exactly the above problem! It should be easy to modify the code for an [`O(n)` solution](P53.cpp) (and `O(1)` space).

Apparently, there is a named algorithm, known as [Kadane's algorithm](https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/), for this problem. I think its idea is the same.
