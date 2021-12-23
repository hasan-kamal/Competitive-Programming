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

	vi ans(10001, INT_MAX);
	ans[0] = 0;
	ans[1] = 1;
	for(int i = 2; i <= 10000; i++)
		for(int j = 1; j * j <= i; j++)
			ans[i] = min(ans[i], 1 + ans[i - j * j]);

	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		cout << ans[n] << endl;
	}

	return 0;
}