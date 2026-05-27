// Problem Name: CSES Common Divisors
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    vector<int> count(1000005, 0);
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x]++;
        max_val = max(max_val, x);
    }
    for (int gcd = max_val; gcd >= 1; gcd--) {
        int multiples = 0;
        for (int j = gcd; j <= max_val; j += gcd) {
            multiples += count[j];
        }
        if (multiples >= 2) {
            cout << gcd << "\n";
            return 0;
        }
    }
    return 0;
}
