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

vvvi dp;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L = 26;
	int S = (int)1e4;
	dp = vvvi(L, vvi(27, vi(max(27, S + 1), 0)));
	for(int i = 1; i <= 26; i++)
		dp[0][i][i] = 1;
	for(int i = 1; i < L; i++){
		for(int j = 1; j <= 26; j++){
			for(int k = 1; k <= S; k++){
				dp[i][j][k] = 0;
				for(int a = 1; a < j; a++)
					if(k - j > 0)
						dp[i][j][k] += dp[i - 1][a][k - j];
			}
		}
	}


	int l, s;
	int t = 0;
	while(cin >> l >> s){
		if(!l && !s)
			break;
		if(l > 26){
			cout << "Case " << ++t << ": " << 0 << endl;
			continue;
		}
		
		int ans = 0;
		for(int i = 1; i <= 26; i++)
			ans += dp[l - 1][i][s];
		cout << "Case " << ++t << ": " << ans << endl;
	}

	return 0;
}