/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	vll a = vll(n);
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	
	vll max_ind = vll(n);
	max_ind[n - 1] = -1;
	ll max_val = a[n - 1];
	for(ll i = n - 2; i >= 0; i--){

		if(a[i] >= max_val){
			max_ind[i] = -1;
			max_val = a[i];
			continue;
		}

		if(max_ind[i + 1] == -1){
			if(a[i + 1] > a[i])
				max_ind[i] = i + 1;
			else
				max_ind[i] = -1;
			continue;
		}

		if(a[i + 1] > a[max_ind[i + 1]])
			max_ind[i] = i + 1;
		else
			max_ind[i] = max_ind[i + 1];

	}

	ll ans = 0;
	for(ll i = 0; i < n; i++){
		if(max_ind[i] == -1)
			continue;

		ans += (a[max_ind[i]] - a[i]);
	}

	cout << ans;

	return 0;
}