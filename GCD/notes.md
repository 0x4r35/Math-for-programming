# Number Theory: GCD, LCM, and Euclidean Algorithm

## 1. Greatest Common Divisor (GCD)

The Greatest Common Divisor of two integers $a$ and $b$ (denoted as $\gcd(a, b)$) is the largest positive integer that divides both $a$ and $b$ without leaving a remainder.

### Euclidean Algorithm

The Euclidean algorithm is a highly efficient method for computing the GCD of two numbers. It is based on the principle that the greatest common divisor of two numbers does not change if the larger number is replaced by its difference with the smaller number. For efficiency, we use modulo instead of subtraction.

**Equation:**

$$
\gcd(a, b) = \begin{cases} a & \text{if } b = 0 \\ \gcd(b, a \bmod b) & \text{if } b \neq 0 \end{cases}
$$

**Time Complexity:** $\mathcal{O}(\log(\min(a, b)))$

### Extended Euclidean Algorithm

The Extended Euclidean Algorithm not only finds the GCD of $a$ and $b$, but also finds integer coefficients $x$ and $y$ such that:

$$
a \cdot x + b \cdot y = \gcd(a, b)
$$

This equation is known as **Bézout's identity**. This is incredibly useful for finding modular multiplicative inverses and solving linear Diophantine equations.

---

## 2. Least Common Multiple (LCM)

The Least Common Multiple of two integers $a$ and $b$ (denoted as $\text{lcm}(a, b)$) is the smallest positive integer that is divisible by both $a$ and $b$.

---

## 3. GCD–LCM Relationship

There is a fundamental relationship between the GCD and LCM of two numbers $a$ and $b$:

$$
a \cdot b = \gcd(a, b) \cdot \text{lcm}(a, b)
$$

Thus, we can calculate LCM efficiently using the GCD:

$$
\text{lcm}(a, b) = \frac{a \cdot b}{\gcd(a, b)}
$$

> [!TIP]
> **Implementation Note:** In programming, always compute it as `(a / gcd(a, b)) * b` rather than `(a * b) / gcd(a, b)`. This avoids potential integer overflow when computing the product $a \cdot b$.

---

## 4. Important Properties of GCD and LCM

### GCD Properties:

1. **Commutativity:** $\gcd(a, b) = \gcd(b, a)$
2. **Associativity:** $\gcd(a, \gcd(b, c)) = \gcd(\gcd(a, b), c)$
3. **Distributivity:** $\gcd(m \cdot a, m \cdot b) = m \cdot \gcd(a, b)$
4. **GCD of multiple numbers:** $\gcd(a, b, c) = \gcd(\gcd(a, b), c)$
5. **Consecutive integers:** $\gcd(a, a+1) = 1$ (They are always co-prime)
6. **Prime properties:** If $p$ is a prime number, then $\gcd(p, a) = p$ if $p$ divides $a$, otherwise $\gcd(p, a) = 1$.

### LCM Properties:

1. **Commutativity:** $\text{lcm}(a, b) = \text{lcm}(b, a)$
2. **Associativity:** $\text{lcm}(a, \text{lcm}(b, c)) = \text{lcm}(\text{lcm}(a, b), c)$
3. **LCM of multiple numbers:** $\text{lcm}(a, b, c) = \text{lcm}(\text{lcm}(a, b), c)$
4. **Co-prime property:** If $\gcd(a, b) = 1$ (i.e., $a$ and $b$ are co-prime), then $\text{lcm}(a, b) = a \cdot b$

---

## 5. Advanced / Competitive Programming Tricks

- **GCD of an array:** To find the GCD of an array $A = [a_1, a_2, \dots, a_n]$, you can iteratively compute $\gcd(A[i], \text{current GCD})$. You can break early if the running GCD becomes $1$, as it cannot be reduced further.
  
- **Subsegment GCD:** The number of distinct GCDs of all possible subarrays starting at a specific index in an array of size $N$ is bounded by $\mathcal{O}(\log(\max A_i))$. This allows efficient usage of Data Structures like Segment Trees or Sparse Tables to answer range GCD queries in $\mathcal{O}(\log(\max A_i))$ or even $\mathcal{O}(1)$ time.
  
- **Diophantine Equations:** The linear Diophantine equation $ax + by = c$ has a solution (where $x$ and $y$ are integers) **if and only if** $c$ is a multiple of $\gcd(a, b)$.
  
- **C++ Built-in Functions:** From C++17 onwards, `<numeric>` includes `std::gcd(a, b)` and `std::lcm(a, b)` out of the box! However, knowing how to implement them manually (especially the Extended Euclidean Algorithm) is crucial.

---

## 6. CSES Problem: Common Divisors

**Problem Link:** [CSES 1081 - Common Divisors](https://cses.fi/problemset/task/1081)

**Problem Statement:** Given an array of $n$ positive integers, find two integers such that their greatest common divisor is as large as possible. 
- The array elements can be up to $10^6$.
- $n \le 2 \cdot 10^5$.

**Approach:**
1. **The Brute-force Issue:** A brute-force approach to find the GCD of all pairs would take $\mathcal{O}(N^2)$ time, which is too slow for $N = 2 \cdot 10^5$.
2. **Reverse Thinking (Iterating over GCDs):** Instead of iterating over all pairs, we can iterate over all possible values of the GCD from the maximum possible element (e.g., $10^6$) down to $1$.
3. **Counting Multiples:** We can use a frequency array `count` where `count[x]` stores the number of times `x` appears in our input array.
4. **Validating a GCD candidate:** For each candidate GCD, say $g$, we check how many elements in the array are multiples of $g$. We can do this by looping through all multiples of $g$ (i.e., $g, 2g, 3g, \dots$) and summing up their frequencies from the `count` array.
5. **Finding the Maximum:** Since we iterate from the largest possible GCD down to $1$, the first $g$ we find that has at least $2$ multiples in our array is guaranteed to be the maximum possible GCD. We immediately output it and terminate.
6. **Time Complexity:** The outer loop runs $M$ times (where $M = 10^6$ is the max element). The inner loop iterates $M/g$ times. The total number of inner loop iterations across all $g$ is $M \sum_{g=1}^M \frac{1}{g}$, which is a **harmonic series**. The sum of a harmonic series up to $M$ is bounded by $\mathcal{O}(\log M)$. Therefore, the overall time complexity is $\mathcal{O}(M \log M)$, which comfortably runs within the standard 1-second time limit!
