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

# define M 1000000

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	while(cin >> n >> k){
		if(!n && !k)
			continue;
		vvi dp = vvi(k, vi(k * n + 1, 0));
		for(int i = 0; i <= n; i++)
			dp[0][i] = 1;
		for(int i = 1; i < k; i++){
			for(int s = 0; s <= n; s++){
				dp[i][s] = 0;
				for(int j = 0; j <= n; j++){
					if(s - j >= 0){
						dp[i][s] = ( dp[i][s] + dp[i - 1][s - j] ) % M;
					}
				}
			}
		}
		cout << dp[k - 1][n] << endl;
	}

	return 0;
}