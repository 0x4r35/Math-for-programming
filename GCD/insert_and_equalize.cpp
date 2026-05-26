#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    sort(a.begin(), a.end());
    long long g = 0;
    
    for (int i = 0; i < n - 1; i++) {
        g = gcd(g, a[n - 1] - a[i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[n - 1] - a[i]) / g;
    }

    long long curr = a[n - 1];
    set<long long> s(a.begin(), a.end());
    long long added_cost = 0;
    
    while (true) {
        curr -= g;
        added_cost++;
        if (s.find(curr) == s.end()) {
            break;
        }
    }
    
    ans += min(added_cost, (long long)n);
    cout << ans << "\n";
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
