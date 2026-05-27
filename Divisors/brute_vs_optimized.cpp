// Problem Name: Brute Vs Optimized
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDivisorsBrute(int n) {
    vector<int> divisors;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
        }
    }
    return divisors;
}

vector<int> findDivisorsOptimized(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {

            divisors.push_back(i);

            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

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
