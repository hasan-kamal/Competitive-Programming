#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    int positive = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] > 0) {
        positive = i;
        break;
      }
    }

    vii operations;
    if (positive != -1) {
      // There exists a positive element. Make it very large.
      while (a[positive] <= 20) {
        a[positive] *= 2;
        operations.push_back(make_pair(positive, positive));
      }

      // Use it to make all other elements non-negative.
      for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
          a[i] += a[positive];
          operations.push_back(make_pair(i, positive));
        }
      }

      // All elements are non-negative, simple solution exists.
      for (int i = 2; i <= n; i++) {
        operations.push_back(make_pair(i, i - 1));
      }
    }

    if (positive == -1) {
      // All elements are non-positive, simple solution exists.
      for (int i = n - 1; i >= 1; i--) {
        operations.push_back(make_pair(i, i + 1));
      }
    }

    cout << operations.size() << endl;
    for (const auto &pair : operations) {
      cout << pair.first << " " << pair.second << endl;
    }
  }

  return 0;
}