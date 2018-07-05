/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
ii dummy;
const int inf = 1e9;

int maximum(int a, int b){
	return a > b ? a : b;
}

vii dp;
ii f(int n){

	if(dp[n] != dummy)
		return dp[n];

	if(n == 1){
		dp[n] = make_pair(1, 1);
		return dp[n];
	}

	ii ans = make_pair(inf, inf);
	for(int x = 1; x <= n - 1; x++){
		if(maximum(x, f(n - x).second + 1) < ans.second)
			ans = make_pair(x, maximum(x, f(n - x).second + 1));
	}

	if(ans.second > n){
		cout << endl << "debug "<< n << endl;
		ans = make_pair(n, n);
	}

	dp[n] = ans;
	return dp[n];
}

void show_dp(int n){
	for(int i = 1; i <= n; i++)
		cout << i << ". floor=" << dp[i].first << " number_drops=" << dp[i].second << endl;
	cout << endl;
}

int main(){

	dummy = make_pair(-1, -1);
	int n;
	cin >> n;

	dp = vii(n + 1, dummy);
	f(n);
	show_dp(n);

	return 0;
}