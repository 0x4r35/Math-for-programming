// Problem Name: CSES Distributing Apples
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 2e6 + 5;

long long fact[MAX];

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

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

long long nCr(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    long long num = fact[n];
    long long den = (modInverse(fact[r]) * modInverse(fact[n - r])) % MOD;
    return (num * den) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    long long n, m;
    if (cin >> n >> m) {
        cout << nCr(n + m - 1, m - 1) << "\n";
    }

    return 0;
}
