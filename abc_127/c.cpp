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

	int n, m;
	cin >> n >> m;

	vi count(n + 1, 0);

	int l, r;
	for(int i = 0; i < m; i++){
		cin >> l >> r;
		count[l - 1]++;
		count[r]--;
	}

	int ans = (count[0] == m ? 1 : 0);
	for(int i = 1; i <= n; i++){
		count[i] = count[i - 1] + count[i];
		if(count[i] == m)
			ans++;
	}
	cout << ans;

	return 0;
}