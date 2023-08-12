#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if (n == 1) {
      int val;
      cin >> val;
      cout << "NO" << endl;
      continue;
    }

    long long int ones = 0;
    long long int non_ones_cap = 0;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      if (val == 1) {
        ones++;
      } else {
        non_ones_cap += (val - 1);
      }
    }

    if (non_ones_cap >= ones) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}