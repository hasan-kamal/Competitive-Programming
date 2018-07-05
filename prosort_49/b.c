/*
	
@author Hasan Kamal

*/

#include <stdio.h>

typedef unsigned long long int ll;

ll fast_multiply(ll b, ll p, ll m){
	if(p==0)
		return 0;
	else if(p==1)
		return b%m;

	if(p%2==0)
		return (2%m * fast_multiply(b, p/2, m))%m;
	else
		return (b%m + (2%m*fast_multiply(b, (p-1)/2, m))%m)%m;
}

ll fast_exp(ll a, ll b, ll m){
	if(b == 0)
		return 1;
	else if(b==1)
		return a % m;

	ll x = fast_exp(a, b/2, m);
	if(b % 2 == 0)
		return ( fast_multiply(x, x, m) )%m;
	else
		return fast_multiply(fast_multiply(x, x, m), (a%m), m);
}

int main(){

	// ios::sync_with_stdio(false);
	// cin.tie(NULL);

	ll t, a, b, m;
	// cin >> t;
	scanf("%lld", &t);

	while(t--){
		// cin >> a >> b >> m;
		// cout << fast_exp(a, b, m) << endl;

		scanf("%lld %lld %lld", &a, &b, &m);
		printf("%lld\n", fast_exp(a, b, m));
	}

	return 0;
}