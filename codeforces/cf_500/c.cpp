#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

ll minimum(ll a, ll b){
	return a < b ? a : b;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a = vi(2 * n);
	int maxm = -1;
	int minm = INT_MAX;
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
		if(a[i] > maxm)
			maxm = a[i];
		if(a[i] < minm)
			minm = a[i];
	}

	sort(a.begin(), a.end());
	ll ans = ( (ll)(a[n - 1] - a[0]) ) * ( (ll)(a[2 * n - 1] - a[n]) );
	// cout << 0 << " " << ans << endl;

	for(int i = 1; i + n - 1 < 2 * n - 1; i++){
		ans = minimum(ans, ( (ll)(a[i + n - 1] - a[i]) ) * ( (ll)(maxm - minm) ));
		ans = minimum(ans, ( (ll)(maxm - a[i]) ) * ( (ll)(a[n + 1 - 1] - minm) ));
		// cout << i << " " << ans << endl;
	}

	cout << ans;

	return 0;
}