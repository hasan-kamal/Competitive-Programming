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

#define M 1000000007

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int ans = 0;
	ll v;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			v = ((ll)i) * j * (i + j - 2) / 2;
			v %= M;
			ans = (ans + v) % M;
		}
	}

	v = ((ll)n - 1) * (m - 1) * (n + m) / 2;
	v %= M;
	ans = (ans + v) % M;

	// find choose(N, R) % M
	int N = n * m - 2;
	int R = k - 2;
	vi dp(N, 0);
	dp[0] = 1;
	vi dp_cur(N, 0);

	for(int i = 1; i <= N; i++){
		for(int r = 1; i <= N; i++){
			dp_cur[0] = 1;
			dp_cur[r] = dp[r] + dp[r - 1];
		}
	}


	cout << (v * binom) % M;

	return 0;
}