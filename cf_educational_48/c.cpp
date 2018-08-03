#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

#define N 300005
#define up 0
#define down 1

ll maximum(ll a, ll b){
	return a > b ? a : b;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	vll a = vll(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vll b = vll(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	vll total_beyond = vll(n, 0);
	total_beyond[n - 1] = a[n - 1] + b[n - 1];
	for(int i = n - 2; i >= 0; i--){
		total_beyond[i] = total_beyond[i + 1] + a[i] + b[i];
	}

	ll dp[N][2];
	dp[n - 1][up] = b[n - 1];
	dp[n - 1][down] = a[n - 1];

	for(int i = n - 2; i >= 0; i--){
		dp[i][up] =   maximum( (2 * (n - i) - 1) * b[i] + dp[i + 1][up] + total_beyond[i + 1], dp[i + 1][down] + b[i] + 2 * total_beyond[i + 1] );
		dp[i][down] = maximum( (2 * (n - i) - 1) * a[i] + dp[i + 1][down] + total_beyond[i + 1], dp[i + 1][up] + a[i] + 2 * total_beyond[i + 1] );
	}

	cout << dp[0][up];

	// cout << endl;
	// for(int i = 0; i < n; i++){
	// 	cout << dp[i][up] << " ";
	// }
	// cout << endl;
	// for(int i = 0; i < n; i++){
	// 	cout << dp[i][down] << " ";
	// }
	// cout << endl;

	return 0;
}