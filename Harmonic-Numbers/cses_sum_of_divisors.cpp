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

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

long long sum_in_range(long long l, long long r) {
    long long sum = ((l + r) % MOD * ((r - l + 1) % MOD)) % MOD;
    long long inv2 = modInverse(2);
    return (sum * inv2) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    if (!(cin >> n)) return 0;

    long long total_sum = 0;
    
    for (long long l = 1, r; l <= n; l = r + 1) {
        long long q = n / l;
        r = n / q;
        
        long long range_sum = sum_in_range(l, r);
        
        long long term = (range_sum * (q % MOD)) % MOD;
        total_sum = (total_sum + term) % MOD;
    }

    cout << total_sum << "\n";

    return 0;
}
