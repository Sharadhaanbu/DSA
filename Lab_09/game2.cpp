#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> strengths(n);
    for (int i = 0; i < n; ++i) {
      cin >> strengths[i];
    }

    for (int i = 0; i < n; ++i) {
      int max_strength = -1; 
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          max_strength = max(max_strength, strengths[j]);
        }
      }
      cout << strengths[i] - max_strength << (i == n - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}