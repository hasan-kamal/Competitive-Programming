/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#define M 1000000007
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

ll power_exp(ll base, ll p){
	ll ans;
	if(p==0){
		ans = 1%M;
	}else if(p==1){
		ans = base%M;
	}else if(p%2==0){
		ll x = power_exp(base, p/2);
		ans = (x*x)%M;
	}else{
		ll x = power_exp(base, p/2);
		x = (x*x)%M;
		ans = (x*(base%M))%M;
	}
	return ans;
}

int main(){

	ll t, n;
	cin>>t;

	while(t--){
		cin>>n;

		vector<ll> a = vector<ll>(n+1);
		for(ll i=1; i<=n; i++)
			cin>>a[i];

		sort(a.begin()+1, a.end());

		//compute coefficients
		vll coeff_list = vll(n+1);
		for(ll i=1; i<=(n+1)/2; i++){
			ll coeff_term = 1;
			coeff_list[i] = coeff_term;
			ll num, den;
			for(ll x=1; x<=min(i-1, n-i); x++){
				num = (coeff_term * ((i-x)%M))%M;
				num = (num * ((n-i-x+1)%M))%M;
				
				den = x*x;

				coeff_term = ((num%M)*power_exp(den, M-2))%M;
				coeff_list[i] = (coeff_list[i] + (coeff_term%M))%M;
			}
			coeff_list[n-i+1] = coeff_list[i];
		}

		ll ans = 0;
		for(ll i=1; i<=n; i++){
			ans = (ans + ((a[i]%M)*coeff_list[i])%M)%M;
		}

		cout<<ans<<endl;
	}

	return 0;
}