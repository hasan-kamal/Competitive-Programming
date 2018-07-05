#include <stdio.h>
typedef long long int ll;
#define M 1000000007

ll power2(ll n){
	if(n==1)
		return 2;
	else if(n==0)
		return 1;
	else{
		if(n%2==0){
			//n is even
			ll x = (power2(n/2))%M;
			return (x*x)%M;
		}else{
			//n is odd
			ll x = power2(n-1)%M;
			return (2*x)%M;
		}
	}
}

int main(){

	ll t, n, ans, x, a, b;
	scanf("%lld", &t);

	while(t--){
		scanf("%lld", &n);
		//x = (((n%M * n%M)%M - n%M)%M + 2)%M;
		//ans = ( (power2(n-1)*(x%M))%M - 1)%M;
		a = power2(n-1)%M;
		b = ((((n%M)*(n%M))%M - (n%M))%M%M + 2)%M;
		ans = ((a*b)%M-1 + M)%M;
		printf("%lld\n", ans);
	}

	return 0;
}