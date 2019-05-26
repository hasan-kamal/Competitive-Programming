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

vvvll dp;

ll f(int n, int k, int m){
	ll &ans = dp[n][k][m];
	if(ans != -1)
		return ans;

	if(k > n)
		ans = 0;
	else if(n > k * m)
		ans = 0;
	else if(k == 1)
		ans = 1;
	else if(k == 2){
		// n in [2, 2m]
		ll count = 0;
		for(int i = 1; i < n; i++){
			if(max(i, n - i) <= m)
				count++;
		}
		ans = count;
	}else{
		ll count = 0;
		if(k % 2 == 0){
			for(int i = 2; i < n; i++)
				count += f(n - i, k - 2, m) * f(i, 2, m);
		}else{
			for(int i = 1; i <= m; i++){
				if(n - i > 0)
					count += f(n - i, k - 1, m);
			}
		}
		ans = count;
	}
	// cout << n << " " << k << " " << m << " -> " << ans << endl;
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp = vvvll(51, vvll(51, vll(51, -1)));

	ll n, k, m;
	while(cin >> n >> k >> m){
		cout << f(n, k, m) << endl;
	}

	return 0;
}