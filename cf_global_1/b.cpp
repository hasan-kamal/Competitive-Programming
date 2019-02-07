#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int x;
	cin >> x;
	vi diff(n - 1);
	for(int i = 0; i < n - 1; i++){
		int t;
		cin >> t;
		diff[i] = t - x;
		x = t;
	}

	sort(diff.begin(), diff.end());

	ll ans = 0;
	for(int i = 0; i <= n - k - 1; i++)
		ans += diff[i];
	ans += k;
	cout << ans;

	return 0;
}