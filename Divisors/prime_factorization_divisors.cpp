#include <iostream>

using namespace std;

int countDivisors(int n) {
    int count = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int power = 0;

            while (n % i == 0) {
                power++;
                n /= i;
            }

            count *= (power + 1);
        }
    }

    if (n > 1) {
        count *= (1 + 1);
    }
    return count;
}

long long sumOfDivisors(int n) {
    long long sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            long long current_term = 1;
            long long current_power = 1;

            while (n % i == 0) {
                current_power *= i;
                current_term += current_power;
                n /= i;
            }

            sum *= current_term;
        }
    }

    if (n > 1) {
        sum *= (1 + n);
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << countDivisors(n) << "\n";
        cout << sumOfDivisors(n) << "\n";
    }

    return 0;
}
