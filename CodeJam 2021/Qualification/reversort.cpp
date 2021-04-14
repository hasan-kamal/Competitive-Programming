#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GetCost(vector<int> &a, int N) {
    int cost = 0;
    for (int i = 0; i < N - 1; i++) {
        auto it = min_element(a.begin() + i, a.end());
        cost += ((it + 1) - (a.begin() + i));
        reverse(a.begin() + i, it + 1);
    }
    return cost;
}

int main() {

    int T;
    cin >> T;

    int N, cost, case_num = 0;
    while (T--) {
        cin >> N;

        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        cout << "Case #" << ++case_num << ": " << GetCost(a, N) << endl;
    }

    return 0;
}