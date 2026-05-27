#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<long long, long long> remainder_count;
    remainder_count[0] = 1;

    long long prefix_sum = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        long long rem = ((prefix_sum % n) + n) % n;
        
        ans += remainder_count[rem];
        remainder_count[rem]++;
    }

    cout << ans << "\n";

    return 0;
}
