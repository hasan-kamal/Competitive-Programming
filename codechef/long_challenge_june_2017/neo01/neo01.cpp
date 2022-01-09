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

	ll n;
	while(t--){
		
		cin >> n;
		
		vll a = vll(n);
		for(ll i = 0; i < n; i++)
			cin >> a[i];
		
		sort(a.begin(), a.end());

		ll summation_p = 0;
		ll mod_s_p = 0;

		ll negative_cost = 0;
		for(ll i = n - 1; i >= 0; i--){
			if(a[i] >= 0){
				summation_p += a[i];
				mod_s_p += 1;
			}else{

				if( summation_p >= mod_s_p * abs(a[i]) ){
					summation_p += a[i];
					mod_s_p += 1;
				}else{
					negative_cost += a[i];
				}

			}
		}

		cout << mod_s_p * summation_p + negative_cost << endl;
	}

	return 0;
}