/*
	
@author Hasan Kamal

*/

#include <iostream>
#include <cstdio>
using namespace std;

typedef long long int ll;

ll fast_multiply(ll b, ll p, ll m){
	
	if(p == 0)
		return 1 % m;
	else if(p == 1)
		return b % m;

	ll temp = 2 * fast_multiply(b, p/2, m); // can be at max 2*(m-1)
	if(temp>=m)
		temp-=m; //modulo is expensive operation, so do this instead since temp could have been at max 2*(m-1)

	if(p % 2 == 0){
		return temp;	
	}else
		return (b%m + temp)%m;

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