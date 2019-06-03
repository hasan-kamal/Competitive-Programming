#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

typedef vector<int>			vi;
typedef vector<vi>			vvi;
typedef vector<vvi>			vvvi;
typedef long long int 		ll;
typedef vector<ll>			vll;
typedef vector<vll>			vvll;
typedef vector<vvll>		vvvll;

typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef set<int> 			si;

void disp(vvi &a){
	for(int i = 0; i < (int)a.size(); i++){
		for(int j = 0; j < (int)a[0].size(); j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	while(cin >> n >> m){
		if(!n && !m)
			break;
		vi a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			a[i] %= m;
		}

		vvll dp(n, vll(n + 1, 0));
		dp[n - 1][1] = a[n - 1] % m;
		for(int i = n - 2; i >= 0; i--)
			dp[i][1] = (dp[i + 1][1] + a[i]) % m;

		for(int k = 2; k <= n; k++){
			for(int i = n - 1; i >= 0; i--){
				if(i > n - k)
					continue;
				if(i == n - 1){
					dp[i][k] = a[i] % m;
					continue;
				}
				dp[i][k] = (a[i] * dp[i + 1][k - 1]) % m;
				dp[i][k] += dp[i + 1][k];
				dp[i][k] %= m;
			}
		}

		// disp(dp);

		cout << *max_element(dp[0].begin(), dp[0].end()) << endl;
	}

	return 0;
}