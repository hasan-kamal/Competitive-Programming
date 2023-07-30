#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long int n;
    cin >> n;

    int ans = 0;
    for (int i = 1;; i++) {
      if (n % i == 0) {
        ans++;
      } else {
        break;
      }
    }

    cout << ans << endl;
  }

  return 0;
}