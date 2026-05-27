# Permutations, Combinations, and Counting Principles

Combinatorics forms the foundation of counting in competitive programming. We often need to count the number of ways to perform an action or select items, usually modulo $10^9+7$.

## Factorials

The number of ways to arrange $N$ distinct items is $N!$ (N factorial).
$$ N! = N \times (N-1) \times \dots \times 1 $$

In CP, we usually precompute factorials up to $N = 10^6$ in $O(N)$ time.

```cpp
long long fact[MAXN];
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}
```

## Permutations ($^nP_r$)

The number of ways to choose and arrange $r$ elements out of $n$ distinct elements.
$$ ^nP_r = \frac{n!}{(n-r)!} $$

## Combinations ($^nC_r$ or $\binom{n}{r}$)

The number of ways to choose $r$ elements out of $n$ distinct elements (order does not matter).
$$ \binom{n}{r} = \frac{n!}{r!(n-r)!} $$

### Computing $\binom{n}{r}$ with Modular Arithmetic

Since division under a modulo requires the modular multiplicative inverse (using Fermat's Little Theorem):
$$ \binom{n}{r} \equiv n! \times (r!)^{-1} \times ((n-r)!)^{-1} \pmod M $$

```cpp
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    long long num = fact[n];
    long long den = (invFact[r] * invFact[n - r]) % MOD;
    return (num * den) % MOD;
}
```

## Permutations with Repetitions (Multinomial Coefficients)

If we have $N$ items, where item 1 repeats $c_1$ times, item 2 repeats $c_2$ times, ..., and item $k$ repeats $c_k$ times, the number of distinct permutations is:
$$ \frac{N!}{c_1! \times c_2! \times \dots \times c_k!} $$

This is extremely common in string permutation problems.

## Reference Problems & Solutions

### [CSES Creating Strings II](https://cses.fi/problemset/task/1715)
**Approach**: This is a direct application of permutations with repetitions (multinomial coefficients). Given a string of length $N$, we count the frequency of each character $c_i$. The number of unique permutations is $N! / (c_1! \times c_2! \times \dots \times c_{26}!)$. We precompute factorials and use the modular inverse of the denominator to compute the answer modulo $10^9+7$.
