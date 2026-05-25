#include <iostream>

using namespace std;

// Calculates the count of divisors using prime factorization
// Time Complexity: O(sqrt(N))
int countDivisors(int n) {
    int count = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int power = 0;
            // Find the highest power of 'i' that divides 'n'
            while (n % i == 0) {
                power++;
                n /= i;
            }
            // Multiply count by (power + 1)
            count *= (power + 1);
        }
    }
    // If n is a prime number greater than sqrt(original_n)
    if (n > 1) {
        count *= (1 + 1); // Power is 1, so (1 + 1) = 2
    }
    return count;
}

// Calculates the sum of divisors using prime factorization
// Time Complexity: O(sqrt(N))
long long sumOfDivisors(int n) {
    long long sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            long long current_term = 1;
            long long current_power = 1;
            
            while (n % i == 0) {
                current_power *= i;
                current_term += current_power;
                n /= i;
            }
            // Multiply sum by the geometric series sum for this prime factor
            sum *= current_term;
        }
    }
    // If n is a prime number greater than sqrt(original_n)
    if (n > 1) {
        sum *= (1 + n); 
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << countDivisors(n) << "\n";
        cout << sumOfDivisors(n) << "\n";
    }
    
    return 0;
}
