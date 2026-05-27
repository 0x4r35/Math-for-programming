# Binary Exponentiation (Modular Fast Exponentiation)

## What is Binary Exponentiation?
Binary exponentiation (also known as exponentiation by squaring) is a highly efficient algorithm that computes $a^n$ in **$O(\log n)$** time, rather than the naive $O(n)$ time. This optimization is critical in Competitive Programming where $n$ can be extremely large (up to $10^{18}$).

## How it Works
The idea revolves around the binary representation of the exponent.
For example, to compute $3^{13}$:
The number $13$ in binary is $1101_2$, which means $13 = 8 + 4 + 1$.
Therefore: 

$$3^{13} = 3^{8 + 4 + 1} = 3^8 \times 3^4 \times 3^1$$

Instead of multiplying $3$ by itself $13$ times, we repeatedly square the base:
$3^1 = 3$
$3^2 = 9$
$3^4 = 81$
$3^8 = 6561$

We simply multiply our result by the current base whenever the corresponding bit in the exponent's binary representation is `1`.

## Modular Fast Exponentiation
In CP, we usually need the result modulo $M$ (e.g., $10^9 + 7$) because the exact value of $a^n$ is far too large to fit in any standard data type. Since modulo distributes over multiplication, we can take the modulo at every step.

### C++ Implementation
```cpp
long long binpow(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) { // If the current bit is 1
            res = (res * a) % m;
        }
        a = (a * a) % m;  // Square the base
        b /= 2;           // Shift bits to the right
    }
    return res;
}
```

## Properties and Tricks for CP

### 1. Matrix Exponentiation
Binary Exponentiation isn't limited to numbers! You can apply it to matrices. By defining matrix multiplication, you can find the $n$-th term of any linear recurrence relation (like the Fibonacci sequence) in $O(k^3 \log n)$ time, where $k$ is the size of the state matrix.

### 2. Large Modulo Multiplication Overflow
If the modulus $M$ is up to $10^{18}$, then the step `(a * a) % M` will overflow a standard 64-bit `long long`. 
**Trick:** You can cast to `__int128` in GCC/Clang:
`res = (long long)((__int128)res * a % M);`
Alternatively, you can implement a "Binary Multiplication" function (using addition instead of multiplication, mirroring the logic of fast power).

### 3. Extremely Large Exponents (Given as Strings)
If the exponent is given as an astronomically large string (e.g., $10^{100000}$ digits), you cannot fit it into a `long long`. 
**Trick:** If the modulo $M$ is prime, you can reduce the string exponent modulo $M-1$ while reading it digit by digit, thanks to Fermat's Little Theorem.

## Related Problems in this Directory

### 1. [LeetCode 1922: Count Good Numbers](https://leetcode.com/problems/count-good-numbers/)
**Concept:** A digit string is "good" if digits at even indices are even (0, 2, 4, 6, 8) and digits at odd indices are prime (2, 3, 5, 7).
**Explanation:** 
For a string of length $n$:
- There are exactly $\lceil n/2 \rceil$ even indices. We have 5 choices for each.
- There are exactly $\lfloor n/2 \rfloor$ odd indices. We have 4 choices for each.

The total number of good strings is $5^{\lceil n/2 \rceil} \times 4^{\lfloor n/2 \rfloor} \pmod{10^9+7}$.
Because $n$ can be up to $10^{15}$, an $O(n)$ loop will Time Limit Exceed (TLE). We must use **Binary Fast Exponentiation** to calculate these large powers in $O(\log n)$ time.

### 2. [SPOJ LOCKER - Magic of the Locker](https://www.spoj.com/problems/LOCKER/)
**Concept:** You are given a number $N$ and need to break it into a sum of positive integers such that their product is maximized.
**Explanation:** 
This relies on a well-known mathematical trick: breaking a number into as many `3`s as possible yields the absolutely largest product. We check $N \pmod 3$:
- If $N \pmod 3 == 0$, the maximum product is $3^{N/3}$.
- If $N \pmod 3 == 1$, we combine one `3` with the remaining `1` to form a `4` (since $2 \times 2 > 3 \times 1$). The product is $3^{(N/3 - 1)} \times 4$.
- If $N \pmod 3 == 2$, the product is $3^{N/3} \times 2$.

Because $N$ can be extremely large ($10^{12}$), calculating the power of $3$ requires **Modular Fast Exponentiation** in $O(\log N)$ time.
