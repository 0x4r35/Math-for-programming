#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e6;

vector<long long> precompute_aliquot_sums() {
    vector<long long> aliquot_sum(MAXN + 1, 0);

    for (int i = 1; i <= MAXN; ++i) {
        for (int j = i * 2; j <= MAXN; j += i) {
            aliquot_sum[j] += i;
        }
    }
    
    return aliquot_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<long long> aliquot_sum = precompute_aliquot_sums();
    
    cout << "Aliquot sum of 6 is: " << aliquot_sum[6] << "\n"; 
    cout << "Aliquot sum of 28 is: " << aliquot_sum[28] << "\n"; 
    cout << "Aliquot sum of 12 is: " << aliquot_sum[12] << "\n"; 
    cout << "Aliquot sum of 15 is: " << aliquot_sum[15] << "\n"; 
    
    return 0;
}
