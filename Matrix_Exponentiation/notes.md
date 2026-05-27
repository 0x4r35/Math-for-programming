# Matrix Exponentiation

Matrix Exponentiation is an extremely powerful technique used to solve linear recurrences and certain graph problems in $O(K^3 \log N)$ time, where $K$ is the size of the state matrix.

## The Concept

Just like binary exponentiation for scalars allows computing $A^N$ in $O(\log N)$, we can apply the exact same algorithm to matrices.
Since matrix multiplication is associative, we can compute $M^N$ efficiently using repeated squaring.

## 1. Linear Recurrences

Any linear recurrence of the form:

$$ f(n) = c_1f(n-1) + c_2f(n-2) + \dots + c_kf(n-k) $$

can be represented as a matrix multiplication.

### Example: Fibonacci Numbers
The Fibonacci sequence: $F(n) = F(n-1) + F(n-2)$, with $F(0) = 0, F(1) = 1$.
We can express this as:

$$ \begin{bmatrix} F(n) \\ F(n-1) \end{bmatrix} = \begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix} \begin{bmatrix} F(n-1) \\ F(n-2) \end{bmatrix} $$

To find $F(n)$, we raise the transition matrix to the $(n-1)$-th power:

$$ \begin{bmatrix} F(n) \\ F(n-1) \end{bmatrix} = \begin{bmatrix} 1 & 1 \\ 1 & 0 \end{bmatrix}^{n-1} \begin{bmatrix} F(1) \\ F(0) \end{bmatrix} $$

## 2. Paths in a Graph

If you have a directed (or undirected) unweighted graph represented by an adjacency matrix $A$ (where $A_{i,j}$ is the number of edges from $i$ to $j$), then:

> The entry at $(i, j)$ in the matrix $A^K$ represents the exact number of paths of length exactly $K$ from node $i$ to node $j$.

This allows us to count paths of huge lengths $K$ (e.g., $K = 10^{18}$) in $O(V^3 \log K)$ time.

### Extensions
- **Shortest Paths of length $K$**: Replace standard matrix multiplication (which uses $+$ and $\times$) with $(\min, +)$ algebra. Instead of `C[i][j] += A[i][k] * B[k][j]`, use `C[i][j] = min(C[i][j], A[i][k] + B[k][j])`.

## Reference Problems & Solutions

### [CSES Fibonacci Numbers](https://cses.fi/problemset/task/1722)
**Approach**: We formulate the Fibonacci sequence as a matrix multiplication. The transition matrix is `[[1, 1], [1, 0]]`. To find the $N$-th Fibonacci number, we compute `TransitionMatrix^(N-1)` using binary matrix exponentiation in $O(\log N)$ time, and multiply it by the base case matrix.

### [CSES Graph Paths I](https://cses.fi/problemset/task/1723)
**Approach**: We construct the adjacency matrix $A$ for the given directed graph, where $A[i][j]$ is the number of edges from $i$ to $j$. We are looking for the number of paths of exactly length $K$ from node 1 to node $N$. According to matrix exponentiation properties, this is exactly the value at `A^K[0][N-1]`. We use binary matrix exponentiation to compute $A^K$ modulo $10^9+7$.
