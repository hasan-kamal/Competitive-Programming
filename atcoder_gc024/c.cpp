/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

ll absol(ll x){
	return x < 0 ? -1 * x : x;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	vi a(n);
	for(ll i = 0; i < n; i++)
		cin >> a[i];

	for(ll i = 0; i < n; i++){
		if(a[i] > i){
			cout << "-1";
			return 0;
		}
	}

	for(ll i = 1; i < n; i++){
		if(a[i - 1] < a[i] - 1){
			cout << "-1";
			return 0;
		}
	}

	ll ans = 0;
	ll i = n - 1;
	while(i > 0){
		if(a[i - 1] >= a[i]){
			ans += a[i];
			i -= 1;
		}else{
			ans += a[i];
			while(i - 1 >= 0 && a[i - 1] == a[i] - 1)
				i -= 1;
			if(i < 0)
				break;
			i -= 1;
		}
	}
	cout << ans;

	return 0;
}