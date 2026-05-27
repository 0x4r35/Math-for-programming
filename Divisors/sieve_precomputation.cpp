#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100005;
int divCount[MAXN];
long long divSum[MAXN];

void precomputeDivisors() {

    for (int i = 1; i < MAXN; i++) {
        divCount[i] = 0;
        divSum[i] = 0;
    }

    for (int i = 1; i < MAXN; i++) {

        for (int j = i; j < MAXN; j += i) {
            divCount[j]++;
            divSum[j] += i;
        }
    }
}

int main() {
    precomputeDivisors();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << divCount[n] << " " << divSum[n] << "\n";
    }

    return 0;
}
