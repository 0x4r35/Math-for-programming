#include <iostream>
#include <vector>
#include <string>

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

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    vector<int> counts(26, 0);
    for (char c : s) {
        counts[c - 'a']++;
    }

    long long ans = fact[n];
    long long denom = 1;
    for (int count : counts) {
        if (count > 0) {
            denom = (denom * fact[count]) % MOD;
        }
    }

    ans = (ans * modInverse(denom)) % MOD;
    cout << ans << "\n";

    return 0;
}
