#include <iostream>
using namespace std;
const int MAX_X = 1e6 + 5;
int spf[MAX_X];
// Precompute Smallest Prime Factor (SPF) using Sieve
// Time Complexity: O(MAX_X * log(log(MAX_X)))
void sieve() {
    // Initialize SPF to each value 
    for (int i = 1; i < MAX_X; i++) {
        spf[i] = i;
    }
    
    for (int i = 2; i * i < MAX_X; i++) {
        if (spf[i] == i) { // i is prime 
            for (int j = i * i; j < MAX_X; j += i) {
                if (spf[j] == j) { // Mark smallest prime factor
                    spf[j] = i;
                }
            }
        }
    }
}

// Function to count divisors using SPF in O(log n) time 
int countDivisorsFast(int n) {
    int count = 1;
    while (n != 1) {
        int prime = spf[n];
        int power = 0;
        
        // Count the power of this prime factor
        while (n % prime == 0) {
            power++;
            n /= prime;
        }
        
        count *= (power + 1);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << countDivisorsFast(x) << "\n";
    }

    return 0;
}
