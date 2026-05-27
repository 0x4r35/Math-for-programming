# Stars and Bars

The "Stars and Bars" method is a graphical aid for deriving certain combinatorial theorems. It is incredibly useful in CP for problems that involve distributing identical items into distinct groups.

## Theorem 1 (Positive Integers)
The number of ways to put $n$ indistinguishable items into $k$ distinguishable boxes such that **every box receives at least one item** is:
$$ \binom{n-1}{k-1} $$

**Intuition:** Imagine $n$ items (stars) in a line. There are $n-1$ spaces between them. To divide them into $k$ groups, we need to place $k-1$ dividers (bars) into these $n-1$ spaces.

## Theorem 2 (Non-negative Integers)
The number of ways to put $n$ indistinguishable items into $k$ distinguishable boxes where **boxes can be empty** is:
$$ \binom{n+k-1}{k-1} $$

**Intuition:** Add a "dummy" item to each of the $k$ boxes. Now we are distributing $n+k$ items into $k$ boxes such that each box has at least one item. By Theorem 1, this is:
$$ \binom{(n+k)-1}{k-1} = \binom{n+k-1}{k-1} $$

## Typical CP Problem: Distributing Apples
"You have $n$ apples and $m$ children. How many ways can you distribute the apples if some children might get no apples?"
Answer: $\binom{n+m-1}{m-1} \pmod M$

## Reference Problems & Solutions

### [CSES Distributing Apples](https://cses.fi/problemset/task/1716)
**Approach**: We have $n$ apples (indistinguishable) and $m$ children (distinguishable boxes). Since a child can get zero apples, this directly matches Theorem 2. The formula is $\binom{n+m-1}{m-1}$. We implement this by precomputing factorials and using modular inverse for the combinations formula $C(N, R) = N! / (R! \times (N-R)!)$.
