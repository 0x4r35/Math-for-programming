# Fermat's Little Theorem (Must Know for CP)

## What is Fermat's Little Theorem?
Fermat's Little Theorem (FLT) states that if $P$ is a prime number, then for any integer $A$ that is not divisible by $P$:
$$A^{P-1} \equiv 1 \pmod P$$

Alternatively, stated in a way that applies to any integer $A$:
$$A^P \equiv A \pmod P$$

## Full Intuition and Proof
Consider a prime modulus $P$. The set of all non-zero remainders modulo $P$ is: 
$$S = \{1, 2, 3, \dots, P-1\}$$

If we pick an integer $A$ (which is coprime to $P$) and multiply every element in $S$ by $A$, we generate a new set:
$$S' = \{A \cdot 1, A \cdot 2, A \cdot 3, \dots, A \cdot (P-1)\}$$

Because $P$ is a prime and $\gcd(A, P) = 1$, all elements in $S'$ will leave **distinct** remainders modulo $P$, and none of them will leave a remainder of $0$.
Therefore, the remainders of the elements in $S'$ are simply a permutation (a reordering) of the elements in $S$.

If we multiply all the elements in $S$ together, the product must be congruent to the product of all elements in $S'$ modulo $P$:
$$(1 \cdot 2 \dots (P-1)) \equiv (A \cdot 1) \cdot (A \cdot 2) \dots (A \cdot (P-1)) \pmod P$$
$$(P-1)! \equiv A^{P-1} \cdot (P-1)! \pmod P$$

Since $(P-1)!$ is completely coprime to $P$, we can cancel it out from both sides, leaving the core theorem:
$$1 \equiv A^{P-1} \pmod P$$

---

## Application in CP: Modular Multiplicative Inverse
The primary and most crucial use of Fermat's Little Theorem in Competitive Programming is to find the **Modular Multiplicative Inverse**.

When calculating combinations like $nCr = \frac{n!}{r!(n-r)!}$, we must perform division modulo $P$.
We know that division modulo $P$ is mathematically equivalent to multiplying by the inverse: 
$$A / B \equiv A \cdot B^{-1} \pmod P$$

From FLT, we know:
$$B^{P-1} \equiv 1 \pmod P$$

We can split one $B$ out from the exponent:
$$B \cdot B^{P-2} \equiv 1 \pmod P$$

By the strict mathematical definition of an inverse ($B \cdot B^{-1} \equiv 1$), it becomes obvious that:
$$B^{-1} \equiv B^{P-2} \pmod P$$

### C++ Code for Modular Inverse
Since $P$ is typically very large (like $10^9+7$), we compute $B^{P-2}$ efficiently using **Binary Exponentiation** in $O(\log P)$ time.

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

// Function to find modular inverse of n modulo p
long long modInverse(long long n, long long p) {
    // Note: This approach works ONLY if p is a prime number!
    return power(n, p - 2, p);
}
```

## Properties and Tricks for CP

### 1. Strictly for Primes
Fermat's Little Theorem **only works if the modulus $P$ is prime**. If $P$ is a composite number (like $10^9$ or $100$), you cannot use FLT to find the modular inverse. In those cases, you must use **Euler's Totient Theorem** ($B^{\phi(M)-1} \pmod M$) or the **Extended Euclidean Algorithm**.

### 2. Exponent Reduction (Power Towers)
When you are asked to calculate massive chained exponents like $A^{B^C} \pmod P$, you apply FLT to the exponent.
Since $A^X \equiv A^{X \pmod{P-1}} \pmod P$, you can safely calculate the exponent as $X = B^C \pmod{P-1}$, and then calculate $A^X \pmod P$.
**Caution:** The exponent's modulo is $P-1$, not $P$!

### 3. Fermat Primality Test
FLT can be used in reverse to check if a number is prime. If you pick a random $A$ and $A^{P-1} \not\equiv 1 \pmod P$, then $P$ is **definitely composite**. If it does equal $1$, $P$ is *probably* prime. This forms the mathematical basis for fast probabilistic primality testing (like the Miller-Rabin test).
