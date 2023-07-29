#include <iostream>
using namespace std;

int main() {
  
  int t;
  cin >>  t;

  while (t--) {
    int n;
    cin >> n;

    int same_chair = 0;
    for (int i = 1; i <= n; i++) {
      int p_i;
      cin >> p_i;
      if (p_i == i) same_chair++;
    }

    if (same_chair % 2 == 0)
      cout << same_chair / 2 << endl;
    else 
      cout << same_chair / 2 + 1 << endl;
  }

  return 0;
}