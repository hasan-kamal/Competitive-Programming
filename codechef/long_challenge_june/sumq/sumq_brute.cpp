/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

int main(){

	ll t;
	cin >> t;

	ll p, q, r;
	while(t--){
		cin >> p >> q >> r;

		vll a = vll(p);
		vll b = vll(q);
		vll c = vll(r);

		for(int i = 0; i < p; i++)
			cin >> a[i];

		for(int i = 0; i < q; i++)
			cin >> b[i];

		for(int i = 0; i < r; i++)
			cin >> c[i];

		ll ans = 0;
		for(int i = 0; i < p; i++){
			for(int j = 0; j < q; j++){
				for(int k = 0; k < r; k++){
					int x = a[i];
					int y = b[j];
					int z = c[k];
					if( x <= y && y >= z)
						ans += (x + y)*(y + z);
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}