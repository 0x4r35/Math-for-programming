// Problem Name: CSES Counting Divisors
#include <iostream>
using namespace std;
const int MAX_X = 1e6 + 5;
int spf[MAX_X];

void sieve() {

    for (int i = 1; i < MAX_X; i++) {
        spf[i] = i;
    }

    for (int i = 2; i * i < MAX_X; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX_X; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

int countDivisorsFast(int n) {
    int count = 1;
    while (n != 1) {
        int prime = spf[n];
        int power = 0;

        while (n % prime == 0) {
            power++;
            n /= prime;
        }

        count *= (power + 1);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        cout << countDivisorsFast(x) << "\n";
    }

    return 0;
}
