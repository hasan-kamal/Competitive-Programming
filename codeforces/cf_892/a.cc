#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    int max = -1, max_count = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] > max) {
        max = a[i];
        max_count = 1;
      } else if (a[i] == max) {
        max_count++;
      }
    }

    if (max_count == n) {
      cout << "-1" << endl;
      continue;
    }

    cout << n - max_count << " " << max_count << endl;
    for (int i = 0; i < n; i++) {
      if (a[i] != max) {
        cout << a[i] << " ";
      }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      if (a[i] == max) {
        cout << a[i] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}