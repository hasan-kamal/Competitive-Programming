#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int best_ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        const int max = i * j;
        int ans = 0;

        std::set<int> available;
        for (int k = 1; k <= n; k++) {
          if (k != j) {
            available.insert(k);
          }
        }

        for (int k = n; k >= 1; k--) {
          if (k != i) {
            auto it = available.upper_bound(max / k);
            if (it == available.begin()) {
              ans = -1;
              break;
            }
            it--;
            int val = *it;
            ans += (k * val);
            available.erase(it);
          }
        }

        if (ans != -1 && ans > best_ans) {
          best_ans = ans;
        }
      }
    }

    cout << best_ans << endl;
  }

  return 0;
}