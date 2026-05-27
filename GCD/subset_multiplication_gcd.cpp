// Problem Name: Subset Multiplication Gcd
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int max_val = 0;
    vector<int> freq(1000005, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        max_val = max(max_val, x);
    }

    vector<long long> dp(max_val + 1, 0);

    for (int i = max_val; i >= 1; i--) {
        int count_multiples = 0;
        for (int j = i; j <= max_val; j += i) {
            count_multiples += freq[j];
        }

        long long subsets = (power(2, count_multiples) - 1 + MOD) % MOD;

        for (int j = 2 * i; j <= max_val; j += i) {
            subsets = (subsets - dp[j] + MOD) % MOD;
        }

        dp[i] = subsets;
    }

    cout << dp[1] << "\n";

    return 0;
}
