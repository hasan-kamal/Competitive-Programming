#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int inv_idx = -1;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] > a[i + 1]) {
        inv_idx = i;
        break;
      }
    }

    if (inv_idx == -1) {
      cout << 0 << endl;
      continue;
    }

    int max_idx = 0;
    for (int i = 1; i <= inv_idx; i++) {
      if (a[i] > a[max_idx]) {
        max_idx = i;
      }
    }

    cout << a[inv_idx] + (a[max_idx] - a[inv_idx]) << endl;
  }

  return 0;
}