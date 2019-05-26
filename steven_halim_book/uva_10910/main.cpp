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

vvi dp;
int P;

int f(int s, int t){
	if(dp[s][t] >= 0)
		return dp[s][t];
	if(s == 0){
		if(t >= P)
			dp[s][t] = 1;
		else
			dp[s][t] = 0;
		return dp[s][t];
	}

	int ans = 0;
	for(int i = P; i <= t; i++){
		ans += f(s - 1, t - i);
	}
	return dp[s][t] = ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> K;

	int N, T;
	while(K--){
		cin >> N >> T >> P;
		dp = vvi(N, vi(T + 1, -1));
		cout << f(N - 1, T) << endl;
	}

	return 0;
}