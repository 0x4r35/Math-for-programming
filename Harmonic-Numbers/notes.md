# Harmonic Numbers in Competitive Programming

## What are Harmonic Numbers?
The $n$-th harmonic number, denoted as $H_n$, is the sum of the reciprocals of the first $n$ natural numbers:
$$H_n = 1 + \frac{1}{2} + \frac{1}{3} + \dots + \frac{1}{n} = \sum_{i=1}^n \frac{1}{i}$$

## Convergent and Divergent Series
- **Divergence:** The harmonic series diverges to infinity as $n \to \infty$. Even though the terms get progressively smaller, they do not get smaller fast enough for the series to converge to a finite limit.
- **Approximation:** For large $n$, $H_n$ can be closely approximated as:
  $$H_n \approx \ln(n) + \gamma$$
  where $\gamma \approx 0.5772156649$ is the Euler-Mascheroni constant.

## Why Harmonic Numbers Matter in C++ (Competitive Programming)
In Competitive Programming, the most common application of harmonic numbers is **Harmonic Series Complexity**. 
Often, when you iterate through multiples of numbers, the total number of iterations is bounded by the harmonic series.

$$\sum_{i=1}^n \frac{n}{i} = n \left(1 + \frac{1}{2} + \frac{1}{3} + \dots + \frac{1}{n}\right) = n H_n$$

Since $H_n \approx \ln(n)$, the sum is mathematically bounded by **$O(n \log n)$**. This means nested loops that look like $O(n^2)$ might actually run much faster!

## Basic and Advanced Concepts

### 1. The "Sieve" Approach for Multiples/Divisors
A naive approach to find all divisors for every number from $1$ to $N$ takes $O(N \sqrt{N})$. However, by iterating over multiples using the harmonic series concept, we can do it in **$O(N \log N)$**.

```cpp
// Time Complexity: O(N log N)
int n = 1e6;
vector<vector<int>> divisors(n + 1);

for (int i = 1; i <= n; ++i) {
    // Jump by 'i' instead of 1
    for (int j = i; j <= n; j += i) {
        divisors[j].push_back(i);
    }
}
```

### 2. Properties
- $H_n$ grows extremely slowly. For $n = 10^6$, $H_n \approx 14.39$. For $n = 10^9$, $H_n \approx 21.30$.
- $H_n$ is **never an integer** for any $n > 1$.

### 3. Harmonic Lemma (Square Root Decomposition of Fractions)
This is an advanced trick for calculating sums like $\sum_{i=1}^n \lfloor \frac{n}{i} \rfloor$ in $O(\sqrt{n})$ time instead of $O(n)$.
The key observation is that the sequence $\lfloor \frac{n}{i} \rfloor$ takes at most $2\sqrt{n}$ distinct values. We can group these identical values into blocks and process them together.

```cpp
// Calculating sum of floor(n/i) for i from 1 to n
long long n = 1e12;
long long ans = 0;

for (long long l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l);
    // n / i has the exact same value for all i in [l, r]
    long long value = n / l;
    long long count_in_block = (r - l + 1);
    ans += count_in_block * value;
}
```
**Time Complexity:** $O(\sqrt{N})$

## Tricks for CP
1. **Precomputing Multiples:** Whenever you see constraints like $N \le 10^5$ and need to compute something over divisors, using an outer loop for $i$ from $1 \dots N$ and an inner loop over $i, 2i, 3i \dots$ is extremely efficient ($O(N \log N)$).
2. **Frequency Array & Multiples:** If you want to check how many elements in an array are divisible by $X$, you can store frequencies of all array elements, and then iterate over all multiples of $X$. 

## Problems & Applications

### 1. Codeforces - We Were Both Children (1850F)
**Concept:** Frogs jump in lengths of $a_i$. We want to find the coordinate where the maximum number of frogs land.
**Idea:** Instead of simulating each frog, count the frequency of jump lengths. Then, for each jump length $i$, add its frequency to all its multiples (the spots it lands on). Since the inner loop increments by $i$, the time complexity is governed by the harmonic series $\sum \frac{n}{i} = O(N \log N)$.

### 2. Aliquot Sum
**Concept:** The Aliquot sum $s(n)$ of a positive integer $n$ is the sum of all proper divisors of $n$ (all divisors excluding $n$ itself).
**Idea:** To compute the Aliquot sum for all numbers from $1$ to $N$, you can use the harmonic sieve:
```cpp
vector<long long> aliquot_sum(N + 1, 0);
for (int i = 1; i <= N; ++i) {
    for (int j = i * 2; j <= N; j += i) { // Start from i*2 to exclude the number itself
        aliquot_sum[j] += i;
    }
}
// Time Complexity: O(N log N)
```

### 3. CSES - Sum of Divisors
**Concept:** Calculate $\sum_{i=1}^n \sigma(i)$ modulo $10^9+7$, where $\sigma(i)$ is the sum of divisors of $i$. $N$ can be up to $10^{12}$.
**Idea:** Writing out the sum reveals that the term $i$ appears exactly $\lfloor \frac{n}{i} \rfloor$ times. 
So, the total sum is equal to: $\sum_{i=1}^n i \times \lfloor \frac{n}{i} \rfloor$.
Because $N$ is up to $10^{12}$, an $O(N)$ approach will yield Time Limit Exceeded (TLE). You must use the **Harmonic Lemma** mentioned above to group ranges of $i$ where $\lfloor \frac{n}{i} \rfloor$ is constant, calculating the sum of the arithmetic progression for each block in $O(\sqrt{N})$ time.
