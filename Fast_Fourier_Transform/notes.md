# Fast Fourier Transform (FFT)

The Fast Fourier Transform (FFT) is an algorithm that computes the Discrete Fourier Transform (DFT) in $O(N \log N)$ time, heavily used in competitive programming to multiply two polynomials efficiently.

## Polynomial Multiplication

Given two polynomials:

$$ A(x) = a_0 + a_1x + a_2x^2 + \dots + a_{n-1}x^{n-1} $$

$$ B(x) = b_0 + b_1x + b_2x^2 + \dots + b_{m-1}x^{m-1} $$

The naive multiplication takes $O(n \times m)$ time. FFT reduces this to $O(N \log N)$, where $N$ is the smallest power of 2 greater than $n+m-1$.

## Complex Roots of Unity
The magic of FFT lies in evaluating polynomials at the $N$-th complex roots of unity. An $N$-th root of unity is a complex number $\omega$ such that $\omega^N = 1$. The principal $N$-th root is:

$$ \omega_N = e^{2\pi i / N} = \cos(2\pi/N) + i\sin(2\pi/N) $$

## The FFT Algorithm Steps

1.  **Evaluation (DFT):** Convert polynomial representations from coefficient form to point-value form by evaluating them at the $N$ complex roots of unity using FFT. Takes $O(N \log N)$.
2.  **Point-wise Multiplication:** Multiply the evaluated values of both polynomials: $C(\omega_N^k) = A(\omega_N^k) \times B(\omega_N^k)$. Takes $O(N)$.
3.  **Interpolation (Inverse DFT):** Convert the result back from point-value form to coefficient form using the Inverse FFT. Takes $O(N \log N)$.

## Number Theoretic Transform (NTT)

When calculations are required modulo a prime $P$ (usually of the form $c \times 2^k + 1$, like $998244353$), we use NTT. NTT uses modulo arithmetic and a primitive root $g$ modulo $P$ instead of complex numbers. The primitive root acts exactly like the complex roots of unity.

### Standard NTT Primes:
- $998244353 = 119 \times 2^{23} + 1$, primitive root $g = 3$
- $1004535809 = 479 \times 2^{21} + 1$, primitive root $g = 3$

## Reference Problems & Solutions

### [CSES Apples and Bananas](https://cses.fi/problemset/task/2111)
**Approach**: We represent the weights of apples and bananas as coefficients of two polynomials. If an apple has weight $w$, we increment the coefficient of $x^w$ in polynomial $A$. If a banana has weight $w$, we increment the coefficient of $x^w$ in polynomial $B$. The problem asks for the number of ways to pick an apple and a banana such that their total weight is $k$. This is exactly the coefficient of $x^k$ in the product polynomial $C(x) = A(x) \times B(x)$. We use the iterative FFT algorithm to multiply these polynomials in $O(K \log K)$ time.
