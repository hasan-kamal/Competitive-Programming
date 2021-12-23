/*

@author hasankamal

*/

#include <iostream>
#include <climits>
using namespace std;
typedef long long int ll;

const int M = 998244353;
const int N = 300005;
const int ALPHA = 20;
int dp[N][ALPHA][ALPHA];

ll a, b;
ll f(ll n, ll K, ll alpha, ll beta){

	cout << alpha << " " << beta << endl;

	if(n == 1){
		ll k = K - a * alpha - b * beta;
		
		if(k == 0){
			return 1;
		}
		if(k == a){
			return 1;
		}
		if(k == b){
			return 1;
		}
		if(k == a + b){
			return 1;
		}

		return 0;
	}

	if(dp[n][alpha][beta] != -1)
		return dp[n][alpha][beta];

	ll ans = f(n - 1, K, alpha + 1, beta) + f(n - 1, K, alpha, beta + 1) + f(n - 1, K, alpha + 1, beta + 1) + f(n - 1, K, alpha, beta);
	ans = ans % M;
	dp[n][alpha][beta] = ans;
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0; i < N; i++){
		for(int j = 0; j < ALPHA; j++)
			for(int k = 0; k < ALPHA; k++)
				dp[i][j][k] = -1;
	}

	ll n, k;
	cin >> n >> a >> b >> k;

	cout << f(n, k, 0, 0);
	
	return 0;
}