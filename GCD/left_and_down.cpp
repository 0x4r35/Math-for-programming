#include <iostream>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m;
    if (cin >> n >> m) {
        cout << n + m - gcd(n, m) << "\n";
    }
    
    return 0;
}
