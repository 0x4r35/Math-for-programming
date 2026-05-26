#include <iostream>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;
    
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
    
public:
    int countGoodNumbers(long long n) {
        long long even_positions = (n + 1) / 2;
        long long odd_positions = n / 2;
        
        long long even_choices = power(5, even_positions);
        long long odd_choices = power(4, odd_positions);
        
        return (even_choices * odd_choices) % MOD;
    }
};

int main() {
    Solution sol;
    long long n = 50;
    cout << sol.countGoodNumbers(n) << "\n";
    return 0;
}
