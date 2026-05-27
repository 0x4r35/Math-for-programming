#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

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

void solve() {
    long long n;
    cin >> n;

    if (n < 3) {
        cout << n << "\n";
        return;
    }

    if (n % 3 == 0) {
        cout << power(3, n / 3) << "\n";
    } else if (n % 3 == 1) {
        cout << (power(3, n / 3 - 1) * 4) % MOD << "\n";
    } else {
        cout << (power(3, n / 3) * 2) % MOD << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
