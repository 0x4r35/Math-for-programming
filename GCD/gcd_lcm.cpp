#include <vector>
using namespace std;
long long gcd_iterative(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long gcd_recursive(long long a, long long b) {
    if (b == 0) return a;
    return gcd_recursive(b, a % b);
}
long long lcm_custom(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd_iterative(a, b)) * b;
}
long long extended_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
long long array_gcd(const vector<long long>& arr) {
    if (arr.empty()) return 0;
    long long result = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        result = gcd_iterative(result, arr[i]);
        if (result == 1) {
            return 1;
        }
    }
    return result;
}
long long array_lcm(const vector<long long>& arr) {
    if (arr.empty()) return 0;
    long long result = arr[0];

    for (size_t i = 1; i < arr.size(); ++i) {
        result = lcm_custom(result, arr[i]);
    }
    return result;
}
int main() {
    return 0;
}
