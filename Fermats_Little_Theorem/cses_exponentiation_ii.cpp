#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

long long binpow(long long base, long long exp, long long mod) {
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
            long long a, b, c;
            cin >> a >> b >> c;
            
            long long power_bc = binpow(b, c, MOD - 1);
            cout << binpow(a, power_bc, MOD) << "\n";
        }
    }
    return 0;
}
