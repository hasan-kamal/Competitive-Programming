#include <iostream>
#define M 1000000007
#define N 1002
using namespace std;

typedef long long int ll;
ll dp[N + 5][N + 5];

ll my_pow(ll base, ll pow){
	if(pow == 0)
		return 1;
	ll h = my_pow(base, pow / 2);
	if(pow % 2 == 0){
		return ( h * h ) % M;
	}
	return ( ( h * h ) % M * (base % M) )  % M;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1][1] = dp[1][0] = 1;
	for(ll n = 2; n <= N; n++){
		for(ll r = 0; r <= n; r++){
			if(r == 0 || r == n){
				dp[n][r] = 1;
				continue;
			}

			dp[n][r] = ( dp[n - 1][r] + dp[n - 1][r - 1] ) % M;
		}
	}

	ll t;
	cin >> t;

	ll a, b, c;
	while(t--){
		cin >> a >> b >> c;

		ll term1 = (my_pow(2, c) - 1 + M) % M;
		ll term2 = 0;
		for(ll x = 1; x <= b; x++){
			for(ll y = x + 1; y <= a; y++){
				term2 = ( term2 + ( ((ll)dp[b][x]) * dp[a][y] ) % M ) % M;
			}
		}

		cout << ( ((ll)term1) * term2) % M << endl;
	}

	return 0;
}