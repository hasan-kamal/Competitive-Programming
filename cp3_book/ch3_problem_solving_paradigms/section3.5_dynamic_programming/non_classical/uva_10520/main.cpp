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

typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef set<int> 			si;

typedef vector<ll>			vll;
typedef vector<vll>			vvll;

vvll dp;
int n;

ll f(int i, int j){
	ll &ans = dp[i][j];
	if(ans != -1)
		return ans;
	if(i < j){
		for(int k = i; k < j; k++)
			ans = max(ans, f(i, k) + f(k + 1, j));
		return ans;
	}

	ll l = 0;
	if(i < n){
		l = INT_MIN;
		for(int k = i + 1; k <= n; k++)
			l = max(l, f(k, 1) + f(k, j));
	}

	ll r = 0;
	if(j > 1){
		r = INT_MIN;
		for(int k = 1; k < j; k++)
			r = max(r, f(i, k) + f(n, k));
	}
	ans = l + r;
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a_n1;
	while(cin >> n >> a_n1){
		dp = vvll(n + 1, vll(n + 1, -1));
		dp[n][1] = a_n1;
		cout << f(1, n) << endl;
	}

	return 0;
}