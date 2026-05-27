// Problem Name: CSES Exponentiation
#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        while (n--) {
            long long a, b;
            cin >> a >> b;
            cout << power(a, b, MOD) << "\n";
        }
    }
    return 0;
}
