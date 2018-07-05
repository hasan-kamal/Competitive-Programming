/*

@author Hasan Kamal

*/

#include <iostream>
using namespace std;

typedef long long int ll;

ll maximum(ll a, ll b){
	return a > b ? a : b;
}

int main(){

	ll t;
	cin >> t;

	ll n, b;
	while(t--){
		cin >> n >> b;
		if(n <= b){
			cout << "0" << endl;
			continue;
		}

		ll alpha = n - (n/2/b)*b;
		ll ans = alpha * ((n - alpha) / b);

		alpha = n - b - (n/2/b)*b;
		ans = maximum(ans, alpha * ((n - alpha) / b));

		cout << ans << endl;
	}

	return 0;
}