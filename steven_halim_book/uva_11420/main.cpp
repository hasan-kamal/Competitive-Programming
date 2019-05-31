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


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vvll ans(66, vll(66, -1));
	for(int n = 0; n <= 65; n++){
		for(int s = 0; s <= 65; s++){
			if(n == 0){
				if(s == 0) ans[n][s] = 1;
				else ans[n][s] = 0;
				continue;
			}
			ans[n][s] = (s > 0 ? ans[n - 1][s - 1] : 0);
			for(int j = n - 2; j >= 0; j--)
				ans[n][s] += ans[j][s];
			ans[n][s] += (s == 0 ? 1 : 0);
		}
	}

	int n, s;
	while(cin >> n >> s){
		if(n < 0 && s < 0)
			break;
		cout << ans[n][s] << endl;
	}

	return 0;
}