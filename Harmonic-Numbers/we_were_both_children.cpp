#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n;
    cin >> n;
    
    vector<long long> count(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a <= n) {
            count[a]++;
        }
    }

    vector<long long> traps(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (count[i] == 0) continue;
        
        for (int j = i; j <= n; j += i) {
            traps[j] += count[i];
        }
    }

    long long max_frogs = 0;
    for (int i = 1; i <= n; ++i) {
        max_frogs = max(max_frogs, traps[i]);
    }
    
    cout << max_frogs << "\n";
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
