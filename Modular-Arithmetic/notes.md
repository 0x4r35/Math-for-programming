# Modular Arithmetic Explained for Competitive Programming

## What is Modular Arithmetic?
Modular arithmetic (often called "clock arithmetic") is a system of arithmetic for integers, where numbers "wrap around" upon reaching a certain value the **modulus**. 

In C++, the modulo operator is `%`. However, mathematical modulo and C++ `%` differ slightly when dealing with negative numbers (more on this below).

## Congruence Modulo $M$
Two integers $a$ and $b$ are said to be **congruent modulo $m$**, written as:

$$a \equiv b \pmod m$$

if their difference $(a - b)$ is an integer multiple of $m$, or equivalently, they leave the exact same remainder when divided by $m$.

## Fundamental Properties
If we are working modulo $M$, the following properties hold. These are absolutely essential in CP to avoid integer overflow when dealing with very large calculations.

### 1. Addition

$$(A + B) \pmod M = ((A \pmod M) + (B \pmod M)) \pmod M$$

### 2. Subtraction
In C++, the `%` operator on a negative number returns a negative result (e.g., `-5 % 3 = -2`). In mathematics, modulo should always be positive. The correct way to subtract modulo $M$ is:

$$(A - B) \pmod M = ((A \pmod M) - (B \pmod M) + M) \pmod M$$

*Note: We add $M$ before the final modulo to ensure the result wraps into the strict non-negative range $[0, M-1]$.*

### 3. Multiplication

$$(A \times B) \pmod M = ((A \pmod M) \times (B \pmod M)) \pmod M$$

*Warning: Even if $A \pmod M$ and $B \pmod M$ fit in a 32-bit `int`, their product might not. Always cast to `long long` (or `1LL * A * B`) before multiplying!*

### 4. Division
You **CANNOT** just divide and then take modulo: $(A / B) \pmod M \neq ((A \pmod M) / (B \pmod M)) \pmod M$.
Instead, you must multiply by the **Modular Multiplicative Inverse** of $B$:

$$(A / B) \pmod M = ((A \pmod M) \times B^{-1}) \pmod M$$

---

## Important Concepts & Algorithms

### 1. Modular Exponentiation (Binary Exponentiation)
To compute $A^B \pmod M$ efficiently, you cannot simply multiply $A$ by itself $B$ times (that takes $O(B)$ time). We use Binary Exponentiation, which computes it in **$O(\log B)$** time.

```cpp
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
```

### 2. Modular Multiplicative Inverse
The inverse of $B$ modulo $M$ is a number $B^{-1}$ such that $(B \times B^{-1}) \equiv 1 \pmod M$.
The inverse only exists if $\gcd(B, M) = 1$ (they are coprime).

**Fermat's Little Theorem:**
If $M$ is a prime number (like $10^9+7$), then:

$$B^{M-1} \equiv 1 \pmod M$$

Dividing both sides by $B$:

$$B \times B^{M-2} \equiv 1 \pmod M \implies B^{-1} \equiv B^{M-2} \pmod M$$

So, you can find the inverse using the modular exponentiation function!

```cpp
long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}
```

---

## Tricks and Best Practices for CP
- **Why $10^9+7$ and $998244353$?**
  These are two of the most common moduli used in CP. 
  1. Being prime guarantees that every number from $1$ to $M-1$ has a modular inverse.
  2. $10^9+7$ perfectly fits in a standard 32-bit signed integer.
  3. $(10^9+7)^2 \approx 10^{18}$, which fits safely inside a 64-bit `long long`. This allows doing intermediate multiplications without overflow before the modulo is applied.
  4. $998244353$ is a prime of the form $c \cdot 2^k + 1$, which makes it highly suitable for advanced mathematical transformations like the Number Theoretic Transform (NTT).
- **Negative Modulo Safety:** If you have an expression that could be negative, wrap it defensively: `long long safe_mod = (val % M + M) % M;`

## Problem Explanations (CSES)

### 1. [CSES Exponentiation](https://cses.fi/problemset/task/1095)
**Problem:** Calculate $a^b \pmod{10^9+7}$ for up to $10^5$ test cases. $a, b \le 10^9$.
**Explanation:** This is a direct application of Binary Exponentiation. By breaking $b$ down into its binary representation, we can compute the result in $O(\log b)$ time, easily passing the time limit.

### 2. [CSES Exponentiation II](https://cses.fi/problemset/task/1712)
**Problem:** Calculate $a^{b^c} \pmod{10^9+7}$.
**Explanation:** By Fermat's Little Theorem, we know that $a^{p-1} \equiv 1 \pmod p$ for a prime $p$.
Because of this cyclic nature, the exponent itself repeats every $p-1$ times.
Therefore, $a^{b^c} \pmod p \equiv a^{(b^c \pmod{p-1})} \pmod p$.
Since $p = 10^9+7$, we first calculate $X = b^c \pmod{10^9+6}$. Then we calculate $a^X \pmod{10^9+7}$.

### 3. [CSES Binomial Coefficients](https://cses.fi/problemset/task/1079)
**Problem:** Calculate $nCr \pmod{10^9+7}$ for $10^5$ queries, where $n \le 10^6$.
**Explanation:** We know $nCr = \frac{n!}{r!(n-r)!}$. Since we have many queries, computing factorials each time is too slow.
Instead, we precompute:
1. `fact[i]` = $i! \pmod{10^9+7}$
2. `invFact[i]` = $(i!)^{-1} \pmod{10^9+7}$
Then any $nCr$ query can be answered in $O(1)$ time as `(fact[n] * invFact[r] % MOD * invFact[n-r] % MOD)`.
*Trick:* You only need to compute the inverse of $MAXN!$ using Binary Exponentiation. For all smaller inverses, you can work backwards: $invFact[i] = invFact[i+1] \times (i+1) \pmod{10^9+7}$.
