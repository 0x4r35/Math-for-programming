#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Brute Force Approach we go through all the possible values and check if they are divisors 
// Time Complexity: O(N)
vector<int> findDivisorsBrute(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

// 2. Optimized Approach we only check for values upto sqrt(N) because if d is a divisor then n/d is also a divisor
// Time Complexity: O(sqrt(N))
vector<int> findDivisorsOptimized(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            // 'i' is a divisor
            divisors.push_back(i);
            
            // 'n / i' is also a divisor
            // We check i != n / i to avoid adding the square root twice for perfect squares
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    
    // Sort to maintain ascending order not necessary for competitive programming i did it for better understanding 
    sort(divisors.begin(), divisors.end());
    
    return divisors;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> divBrute = findDivisorsBrute(n);
        for (int d : divBrute) cout << d << " ";
        cout << "\n";
        
        vector<int> divOpt = findDivisorsOptimized(n);
        for (int d : divOpt) cout << d << " ";
        cout << "\n";
    }
    
    return 0;
}
