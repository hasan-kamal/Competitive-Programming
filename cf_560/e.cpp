#include <iostream>
#include <vector>
#include <algorithm>
#define M 998244353
using namespace std;

typedef long long int 	ll;
typedef vector<ll> 		vll;
typedef pair<ll, ll>	llp;
typedef vector<llp>		vllp;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vll a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i] = a[i] * (i + 1) * (n - i);
	}

	vll b(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	ll ans = 0;
	for(ll i = 0; i < n; i++){
		// ans = ans + (a[i] * b[i])
		ans = ( ans + ( (a[i] % M) * (b[i] % M) ) % M ) % M;
	}

	cout << ans;

	return 0;
}