#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int l;
	while(n--){
		cin >> l;
		l /= 100;
		vvi a(10, vi(l));
		for(int i = 9; i >= 0; i--){
			for(int j = 0; j < l; j++)
				cin >> a[i][j];
		}

		vvi dp(10, vi(l, INT_MAX));
		dp[0][l - 1] = 30 - a[0][l - 1];
		dp[1][l - 1] = 20 - a[1][l - 1];
		for(int j = l - 2; j >= 0; j--){
			for(int i = 0; i < 10; i++){
				if(dp[i][j + 1] != INT_MAX)
					dp[i][j] = min(dp[i][j], 30 - a[i][j] + dp[i][j + 1]);
				if(i + 1 < 10 && dp[i + 1][j + 1] != INT_MAX)
					dp[i][j] = min(dp[i][j], 60 - a[i][j] + dp[i + 1][j + 1]);
				if(i - 1 >= 0 && dp[i - 1][j + 1] != INT_MAX)
					dp[i][j] = min(dp[i][j], 20 - a[i][j] + dp[i - 1][j + 1]);
			}
		}

		cout << dp[0][0] << endl;
		cout << endl;
	}

	return 0;
}