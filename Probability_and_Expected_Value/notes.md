# Probability and Expected Value

Probability and Expected Value frequently appear in Dynamic Programming (DP) problems.

## Probability

The probability of an event $A$ is denoted by $P(A)$ and is always $0 \le P(A) \le 1$.
For independent events $A$ and $B$:
$$ P(A \text{ and } B) = P(A) \times P(B) $$
$$ P(A \text{ or } B) = P(A) + P(B) - P(A \text{ and } B) $$

### Probability DP
In probability DP, the state `dp[i][j]` often represents the probability of reaching state $j$ at step $i$.
The transitions are based on the probabilities of moving from a state at step $i-1$ to a state at step $i$.
Since probabilities sum up to 1 over all mutually exclusive and exhaustive outcomes, we just distribute the current state's probability to its next states.

## Expected Value

The Expected Value (or mathematical expectation) of a random variable $X$, denoted by $E[X]$, is the sum of all possible values of $X$ multiplied by their respective probabilities:
$$ E[X] = \sum_{x} x \cdot P(X = x) $$

### Linearity of Expectation (Crucial!)
One of the most important properties in CP is the Linearity of Expectation.
For any two random variables $X$ and $Y$ (even if they are **dependent**!):
$$ E[X + Y] = E[X] + E[Y] $$

This allows us to break down complex expected value problems into sums of simple expectations.

### Expected Value DP
Expected Value DP usually works **backwards**. 
If `dp[i]` is the expected number of steps to reach the end from state $i$:
$$ \text{dp}[i] = 1 + \sum_{j} P(i \to j) \times \text{dp}[j] $$
We define the base case at the end state, e.g., $\text{dp}[N] = 0$, and work backwards to $\text{dp}[1]$.

## Reference Problems & Solutions

### [CSES Dice Probability](https://cses.fi/problemset/task/1725)
**Approach**: We use probability DP. We define `dp[i][j]` as the probability of getting a sum of exactly $j$ after rolling the dice $i$ times. The base case is `dp[0][0] = 1.0` (sum 0 after 0 rolls). For each roll `i`, we transition to sums `j` by adding `dp[i-1][j-k] / 6.0` for each possible dice face `k` from 1 to 6. Finally, we sum the probabilities `dp[n][j]` for all $j$ in the range $[a, b]$.
