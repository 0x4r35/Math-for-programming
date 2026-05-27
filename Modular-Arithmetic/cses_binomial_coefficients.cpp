#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;
const int MAXN = 1e6;

long long fact[MAXN + 1];
long long invFact[MAXN + 1];

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
    invFact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[MAXN] = modInverse(fact[MAXN]);
    for (int i = MAXN - 1; i >= 1; --i) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    long long num = fact[n];
    long long den = (invFact[r] * invFact[n - r]) % MOD;
    return (num * den) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int n;
    if (cin >> n) {
        while (n--) {
            int a, b;
            cin >> a >> b;
            cout << nCr(a, b) << "\n";
        }
    }
    return 0;
}
