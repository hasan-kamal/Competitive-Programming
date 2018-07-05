/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#define M 1000000007
#define N 2001
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
vector<ll> coeff_list;

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

	coeff_list = vll(N);
	for(ll i=1; i<=N; i++){

	}

	ll t, n;
	cin>>t;

	while(t--){
		cin>>n;

		vector<ll> a = vector<ll>(n+1);
		for(ll i=1; i<=n; i++)
			cin>>a[i];

		sort(a.begin()+1, a.end());

		ll ans = 0;
		for(ll i=1; i<=n; i++){
			ll coeff_term = 1;
			ll coeff = coeff_term;
			ll num, den;
			for(ll x=1; x<=min(i-1, n-i); x++){
				// coeff_term=( coeff_term*(i-x)*(n-i-x+1) / ((x)*(x)) );
				// coeff+=coeff_term;
				
				num = (coeff_term * ((i-x)%M))%M;
				num = (num * ((n-i-x+1)%M))%M;
				
				den = x*x;

				coeff_term = ((num%M)*power_exp(den, M-2))%M;
				coeff = (coeff + (coeff_term%M))%M;

				// scale = (i-x)*(n-i-x+1);
				// coeff_term = coeff_term*scale;
				// scale = (x*x);
				// coeff_term = coeff_term/scale;
				// coeff = coeff + coeff_term;
			}
			//ans+=a[i]*coeff;
			
			//ans = ((ans%M) + ((a[i]%M*coeff%M)%M))%M;
			
			ans = (ans + ((a[i]%M)*coeff)%M)%M;
			
			//cout<<i<<" "<<coeff<<endl;
		}

		cout<<ans<<endl;
	}

	return 0;
}