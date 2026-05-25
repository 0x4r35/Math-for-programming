# Divisors in Competitive Programming

## 1. What is a Divisor?
A divisor of an integer `N` is an integer `D` that divides `N` evenly, leaving no remainder (i.e., `N % D == 0`). 
For example, the divisors of $12$ are $1, 2, 3, 4, 6,$ and $12$.

## 2. Algorithm to calculate it (From Brute Force to Optimized)

### Brute Force Approach
The simplest way to find all divisors of `N` is to iterate from `1` to `N` and check if `N % i == 0`.
- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(1)$ (or $O(D)$ to store divisors)

### Optimized Approach 
Divisors always exist in pairs. If `D` is a divisor of `N`, then `N/D` is also a divisor. 
One of these divisors in the pair will always be less than or equal to $\sqrt{N}$, and the other will be greater than or equal to $\sqrt{N}$. 
Thus, we only need to iterate up to $\sqrt{N}$.

- **Time Complexity:** $O(\sqrt{N})$

*See [brute_vs_optimized.cpp] for code examples.*

---

## 3. Count of Divisors using Prime Factorization 
According to the Fundamental Theorem of Arithmetic, any integer `N` greater than 1 can be represented uniquely as a product of prime powers:
$N = p_1^{a_1} \times p_2^{a_2} \times \dots \times p_k^{a_k}$

The number of divisors, often denoted as $\tau(N)$ or $d(N)$, can be found by adding 1 to each exponent and multiplying them together:
**Formula:** $\tau(N) = (a_1 + 1) \times (a_2 + 1) \times \dots \times (a_k + 1)$

**Example:**
$12 = 2^2 \times 3^1$
Number of divisors = $(2 + 1) \times (1 + 1) = 3 \times 2 = 6$.

*See [prime_factorization_divisors.cpp] for implementation.*

---

## 4. Sum of Divisors Formula 
Using the same prime factorization of `N`:
$N = p_1^{a_1} \times p_2^{a_2} \times \dots \times p_k^{a_k}$

The sum of all divisors, denoted as $\sigma(N)$, is calculated using the formula for the sum of a geometric progression for each prime factor:
**Formula:** $\sigma(N) = \left(\frac{p_1^{a_1+1} - 1}{p_1 - 1}\right) \times \left(\frac{p_2^{a_2+1} - 1}{p_2 - 1}\right) \times \dots \times \left(\frac{p_k^{a_k+1} - 1}{p_k - 1}\right)$

*See [prime_factorization_divisors.cpp] for implementation.*

---

## 5. Product of Divisors
Let $P(N)$ be the product of all divisors of `N`. (Note: In some texts Product of Divisors might be denoted differently, but here we can define it as $P(n)$ or similar; $\mu(n)$ typically denotes the Möbius function in number theory, so it's a slight notation mixup, but the concept meant is Product of Divisors).

Since divisors come in pairs that multiply to `N` (e.g., $d$ and $N/d$), we can pair them up.
If there are $\tau(N)$ divisors, there are $\tau(N)/2$ pairs.
**Formula:** $P(N) = N^{\frac{\tau(N)}{2}}$

*Note: If $N$ is a perfect square, $\tau(N)$ is odd, so $\tau(N)/2$ is a fraction, but $N^{\frac{1}{2}}$ is just $\sqrt{N}$, an integer. So it simplifies nicely to $(\sqrt{N})^{\tau(N)}$. In CP, you often have to calculate this modulo $10^9+7$, requiring careful application of Fermat's Little Theorem for the exponent.*

---

## 6. Precomputing Divisors for All Numbers (Sieve Style)
When you need to find the count or sum of divisors for many numbers (e.g., $10^5$ queries for $N \le 10^6$), calculating it per query even in $O(\sqrt{N})$ is too slow.

We can use a Sieve of Eratosthenes-like approach to precompute the count and sum of divisors for all numbers up to $MAX$ in $O(MAX \log MAX)$ time.

**How it works:**
Instead of finding divisors for each number, for each number `i`, we add `i` as a divisor to all its multiples (`i, 2i, 3i, 4i \dots`).

*See [sieve_precomputation.cpp] for implementation.*

---

## 7. Solve Counting Divisors problem from CSES
**Problem Link:** [CSES - Counting Divisors](https://cses.fi/problemset/task/1713)
**Task:** Given $n$ queries, for each query find the number of divisors of $x$. ($n \le 10^5, x \le 10^6$).

**Optimal Approach:** 
Instead of the standard $O(\sqrt{x})$ per query, we can precompute the **Smallest Prime Factor (SPF)** for every number up to $10^6$ using a Sieve. 
Once we have the SPF, we can prime factorize any number $x$ in $O(\log x)$ time.
Total Time Complexity: $O(MAX \log \log MAX)$ for Sieve + $O(n \log x)$ for queries.

*See [cses_counting_divisors.cpp]for the full solution.*
