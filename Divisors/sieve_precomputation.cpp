#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100005;
int divCount[MAXN]; // To store count of divisors
long long divSum[MAXN]; // To store sum of divisors

// Precompute divisor counts and sums using a Sieve-like approach
// Time Complexity: O(MAXN * log(MAXN))
void precomputeDivisors() {
    // Initialize
    for (int i = 1; i < MAXN; i++) {
        divCount[i] = 0;
        divSum[i] = 0;
    }

    // Sieve
    for (int i = 1; i < MAXN; i++) {
        // i is a divisor for all its multiples: i, 2i, 3i, 4i, ...
        for (int j = i; j < MAXN; j += i) {
            divCount[j]++;       // Increment count
            divSum[j] += i;      // Add to sum
        }
    }
}

int main() {
    precomputeDivisors();
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << divCount[n] << " " << divSum[n] << "\n";
    }
    
    return 0;
}
