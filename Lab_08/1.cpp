#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for accumulate
using namespace std;

void solve() {
    int n;
    cout << "Enter the number of towers: ";
    cin >> n;
    
    vector<long long> a(n);
    cout << "Enter the number of blocks in each tower: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_sum = accumulate(a.begin(), a.end(), 0LL);
    long long max_blocks = *max_element(a.begin(), a.end());

    // The maximum blocks on tower 1 after optimal moves
    cout << "Maximum blocks on Tower 1: " << max(max_blocks, (total_sum + 1) / 2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}
