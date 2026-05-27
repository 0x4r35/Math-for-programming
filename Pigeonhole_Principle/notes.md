# Pigeonhole Principle

The Pigeonhole Principle is a simple but surprisingly powerful idea in mathematics and competitive programming.

## The Principle

If you have $N$ items ("pigeons") and you put them into $M$ containers ("pigeonholes"), and if $N > M$, then at least one container must contain more than one item.

More generally, if $N$ items are placed into $M$ containers, then at least one container must contain at least $\lceil N / M \rceil$ items.

## Common Applications in CP

The Pigeonhole Principle often shows up in problems involving:
- Modulo operations and divisibility
- Finding subsets with specific sums
- Proving the existence of a configuration rather than finding it

### Classic Example: Subarray Sum Divisible by $N$
**Problem:** Given an array of $N$ integers, prove there exists a contiguous subarray whose sum is divisible by $N$.

**Proof using Pigeonhole Principle:**
1. Compute the prefix sums of the array: $P_0=0, P_1=A_0, P_2=A_0+A_1, \dots, P_N = \sum_{i=0}^{N-1} A_i$.
2. There are $N+1$ prefix sums ($P_0$ to $P_N$).
3. Take each prefix sum modulo $N$. The possible remainders are $0, 1, 2, \dots, N-1$ (there are exactly $N$ possible remainders).
4. Since we have $N+1$ prefix sums but only $N$ possible remainders, by the Pigeonhole Principle, at least two prefix sums must have the same remainder modulo $N$.
5. Let these be $P_i$ and $P_j$ with $i < j$.
6. $P_j \equiv P_i \pmod N \implies P_j - P_i \equiv 0 \pmod N$.
7. $P_j - P_i$ is exactly the sum of the subarray from index $i$ to $j-1$. Thus, this subarray's sum is divisible by $N$.

This translates into $O(N)$ counting solutions for many CP problems (like CSES Subarray Divisibility).

## Reference Problems & Solutions

### [CSES Subarray Divisibility](https://cses.fi/problemset/task/1662)
**Approach**: We use the Pigeonhole Principle concept combined with prefix sums. We calculate the prefix sums modulo $N$. If two prefix sums have the same remainder modulo $N$, the subarray between them has a sum divisible by $N$. We keep track of the frequencies of each remainder we've seen so far using an array or map. For every prefix sum remainder we encounter, we add its previously seen frequency to our total answer.
