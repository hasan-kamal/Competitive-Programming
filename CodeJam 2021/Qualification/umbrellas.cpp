#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define C 0
#define J 1

int main() {

    int T, case_num = 0;
    cin >> T;

    while (T--) {
        long long int X, Y;
        string S;

        cin >> X >> Y >> S;
        
        int n = S.length();
        vector<vector<long long int>> dp(n, vector<long long int>(2, INT_MAX)); 
        dp[0][C] = dp[0][J] = 0;
        if (S[0] != '?') {
            if (S[0] == 'J') dp[0][C] = INT_MAX;
            if (S[0] == 'C') dp[0][J] = INT_MAX;
        }
        for (int i = 1; i < n; i++) {
            if (S[i] != 'J') dp[i][C] = min(dp[i - 1][J] + Y, dp[i - 1][C]);
            if (S[i] != 'C') dp[i][J] = min(dp[i - 1][C] + X, dp[i - 1][J]);
        }

        cout << "Case #" << ++case_num << ": " << min(dp[n - 1][C], dp[n - 1][J]) << endl;
    }

    return 0;
}