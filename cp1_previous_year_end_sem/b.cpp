/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

ll absol(ll x){
	return x < 0 ? -1  * x : x;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	ll n, h;
	vi count, row_count;
	while(t--){
		cin >> n >> h;
		
		count = vi(n + 1, 0);
		
		ll l, r;
		for(ll i = 0; i < n; i++){
			cin >> l >> r;
			count[l]++;
			count[r + 1]--;
		}

		ll sum = 0;
		row_count = vi(n, 0);
		for(ll i = 0; i < n; i++){
			sum += count[i];
			row_count[i] = absol(n - sum);
		}

		ll ans = 0;
		for(ll i = 0; i <= h - 1; i++)
			ans += row_count[i];
		
		ll temp = ans;
		for(ll i = h; i < n; i++){
			temp += row_count[i];
			temp -= row_count[i - h];

			if(ans > temp)
				ans = temp;
		}

		cout << ans << endl;
	}			

	return 0;
}