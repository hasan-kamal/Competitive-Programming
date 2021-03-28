#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Remap(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) ++a[i];
}

vector<int> RecursivePrint(int N, int C) {

    if (N == 1) {
        vector<int> ans;
        ans.push_back(1);
        return ans;
    }

    int upper_lower = ( ((N - 1) * (N)) / 2 ) - 1;
    int cost_here = max(C - upper_lower, 1);
    
    vector<int> v = RecursivePrint(N - 1, C - cost_here);
    Remap(v);
    reverse(v.begin(), v.begin() + cost_here - 1);

    vector<int> ans;
    ans.insert(ans.end(), v.begin(), v.begin() + cost_here - 1);
    ans.push_back(1);
    ans.insert(ans.end(), v.begin() + cost_here - 1, v.end());

    return ans;
}

void Solve(int N, int C) {
    int C_max = ( (N * (N + 1)) / 2 ) - 1;
    if (C < N - 1 || C > C_max) {
        cout << "IMPOSSIBLE" << endl;
        return;
    } 
    
    vector<int> v = RecursivePrint(N, C);
    for (int elem : v) cout << elem << " ";
    cout << endl;
}

int main() {

    int T, N, C, case_num = 0;
    cin >> T;

    while (T--) {
        cin >> N >> C;
        cout << "Case #" << ++case_num << ": ";
        Solve(N, C);
    }

    return 0;
}