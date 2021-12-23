/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define M 1000000007
typedef long long int ll;
typedef vector<ll> vll;

ll bsearch(vll &a, ll lo, ll hi, ll comp){
	
	ll mid;
	while(lo < hi){
		mid = lo + (hi - lo + 1) / 2;
		if(a[mid] <= comp)
			lo = mid;
		else
			hi = mid - 1;
	}

	if(a[lo] <= comp)
		return lo;
	else
		return -1; // not found

}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t, p, q, r;
	cin >> t;

	while(t--){
		
		cin >> p >> q >> r;

		vll a = vll(p);
		vll b = vll(q);
		vll c = vll(r);

		vll running_sums_a = vll(p);
		vll running_sums_c = vll(r);

		for(ll i = 0; i < p; i++){
			cin >> a[i];
		}

		for(ll i = 0; i < q; i++)
			cin >> b[i];

		for(ll i = 0; i < r; i++){
			cin >> c[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());

		running_sums_a[0] = a[0];
		for(ll i = 1; i < p; i++)
			running_sums_a[i] = (running_sums_a[i-1] + a[i])%M;

		running_sums_c[0] = c[0];
		for(ll i = 1; i < r; i++)
			running_sums_c[i] = (running_sums_c[i-1] + c[i])%M;

		ll ans = 0;

		for(ll y_index = q - 1; y_index >=0; y_index--){
			ll y = b[y_index];
			ll x_index = bsearch(a, 0, p - 1, y);
			ll z_index = bsearch(c, 0, r - 1, y);

			if(x_index == -1 || z_index == -1)
				break; // no triplet possible with this y

			ll t1 = (running_sums_a[x_index] + ((x_index+1)*y)%M)%M;
			ll t2 = (running_sums_c[z_index] + ((z_index+1)*y)%M)%M;
			ans = (ans + (t1 * t2)%M)%M;

			// cout << "y_index = " << y_index << " x_index = " << x_index << " z_index " << z_index << endl;
			// cout << running_sums_a[x_index] << " " << running_sums_c[z_index] << endl;
			// cout << "t1 = " << t1 << " t2 = " << t2 << endl;
		}

		cout << ans << endl;
	}

	return 0;
}