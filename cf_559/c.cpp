#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll ans = 0;

	int n, m;
	cin >> n >> m;

	vi b(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
		ans = ans + (b[i] * (ll)m);
	}
	sort(b.begin(), b.end());

	vi g(m);
	for(int i = 0; i < m; i++){
		cin >> g[i];
	}
	sort(g.rbegin(), g.rend());

	if(g[m - 1] < b[n - 1]){
		cout << "-1";
		return 0;
	}
	
	int times_max_used = 0;
	for(int i = 0; i < m; i++){
		if(g[i] == b[n - 1])
			continue;
		if(times_max_used < m - 1){
			// use largest
			ans += (g[i] - b[n - 1]);
			times_max_used++;
		}else{
			// use second largest
			ans += (g[i] - b[n - 2]);
		}
	}

	cout << ans;

	return 0;
}