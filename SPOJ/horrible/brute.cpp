/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){

	ll t, n, c;
	cin >> t;

	while(t--){
		
		cin >> n >> c;

		vll a = vll(n + 1, 0);

		ll choice, p, q, v;
		for(ll i = 0; i < c; i++){
			cin >> choice;

			if(choice == 0){
				cin >> p >> q >> v;
				
				for(ll x = p; x <= q; x++){
					a[x] += v;
				}

				continue;
			}

			cin >> p >> q;
			ll ans = 0;
			for(ll x = p; x <= q; x++){
				ans += a[x];
			}
			cout << ans << endl;
		}

	}

	return 0;
}