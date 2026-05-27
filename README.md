# Math for Competitive Programming

The Goal of this repo is to teach Math which is required for CP I have tried my best to write it in a proper format I hope it will be helpful.


## Recommended Study Sequence

Mathematics in CP often builds upon itself. For example, you need to understand Modular Arithmetic before you can properly compute Combinatorics under a modulo. 

It is highly recommended to tackle the topics in the following logical sequence:

1. **[Divisors](Divisors/notes.md)**
   - Understanding what divisors are, prime factorization, and counting/summing them efficiently.
2. **[GCD and LCM](GCD/notes.md)**
   - The Euclidean Algorithm, Extended Euclidean Algorithm, and their relationships.
3. **[Harmonic Numbers](Harmonic-Numbers/notes.md)**
   - Harmonic series complexity bounds, crucial for $O(N \log N)$ sieve-like algorithms.
4. **[Modular Arithmetic](Modular-Arithmetic/notes.md)**
   - The core rules of modulo addition, multiplication, and subtraction to prevent integer overflow.
5. **[Binary Exponentiation](Binary_Exponentiation/notes.md)**
   - Fast $O(\log N)$ calculation of large powers and modular exponentiation.
6. **[Fermat's Little Theorem and Modular Inverse](Fermats_Little_Theorem/notes.md)**
   - Required for mathematically performing division under a modulo constraint.
7. **[Permutations, Combinations, and Counting](Permutations_and_Combinations/notes.md)**
   - $nCr$, $nPr$, multinomial coefficients, and counting combinations using factorials and inverses.
8. **[Stars and Bars](Stars_and_Bars/notes.md)**
   - Graphical combinatorial methods for distributing identical items into distinct groups.
9. **[Pigeonhole Principle](Pigeonhole_Principle/notes.md)**
   - Logical proof techniques and their applications to modulo subsets and configurations.
10. **[Fast Fourier Transform (FFT)](Fast_Fourier_Transform/notes.md)**
    - Highly efficient polynomial multiplication in $O(N \log N)$ time.
11. **[Matrix Exponentiation](Matrix_Exponentiation/notes.md)**
    - Solving $K$-th terms of linear recurrences and counting massive graph paths in $O(\log N)$ time.
12. **[Probability and Expected Value](Probability_and_Expected_Value/notes.md)**
    - Understanding independent events, the Linearity of Expectation, and Probability DP.

## Contents

Inside each of the topic directories above, you will find:
- A detailed `notes.md` file featuring theory, mathematical proofs, and advanced competitive programming tricks.
- Selected reference solutions for classic problems (from Codeforces, CSES, SPOJ, etc.) corresponding to the topic.
