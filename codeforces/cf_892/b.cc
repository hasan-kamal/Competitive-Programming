#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> second_min;
    int min = INT_MAX;

    int m;
    for (int i = 0; i < n; i++) {
      cin >> m;

      vector<int> a(m);
      for (int j = 0; j < m; j++) {
        cin >> a[j];
      }
      sort(a.begin(), a.end());

      if (a[0] < min) min = a[0];
      second_min.push_back(a[1]);
    }

    long long int ans = 0;
    sort(second_min.begin(), second_min.end());
    for (int i = 1; i < second_min.size(); i++) {
      ans = ans + second_min[i];
    }
    ans = ans + min;
    cout << ans << endl;
  }

  return 0;
}