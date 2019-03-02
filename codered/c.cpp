#include <cstdio>
#include <iostream>
using namespace std;

typedef long long int ll;

ll lmin(ll a, ll b){
	return a < b ? a : b;
}

ll f(int n, ll a[56], ll p, int ind){
	if(ind == 0){
		if((p >> ind) & 1)
			return a[ind];
		else
			return 0;		
	}

	if((p >> ind) & 1)
		return a[ind] + f(n, a, p, ind - 1);
	else
		return lmin(a[ind], f(n, a, p, ind - 1));
}

int main(){

	// ios::sync_with_stdio(false);
	// cin.tie(NULL);

	int t;
	scanf("%d", &t);

	int cost[56];
	int rmin[56];
	ll a[56];

	int n;
	while(t--){
		scanf("%d", &n);

		ll p;
		scanf("%lld", &p);
		ll p_0 = p;

		
		for(int i = 0; i < n; i++){
			scanf("%d", &cost[i]);
		}

		rmin[n - 1] = cost[n - 1];
		for(int i = n - 2; i >= 0; i--){
			rmin[i] = lmin(rmin[i + 1], cost[i]);
		}

		a[0] = rmin[0];
		for(int i = 1; i <= n - 1; i++){
			a[i] = lmin(2 * a[i - 1], rmin[i]);
		}

		ll two_pow_n = (1 << n);
		ll two_pow_n_min_one = (1 << (n - 1));

		ll ans = 0;
		if(p >= two_pow_n_min_one){
			ans = (a[n - 1] * (p / two_pow_n_min_one));
			p = p % two_pow_n_min_one;
		}

		// for(int i = 0; i <= n - 1; i++){
		// 	printf("%d %lld\n", i, a[i]);
		// }

		// printf("%lld\n", two_pow_n_min_one);
		// printf("%lld\n", p);
		// printf("%lld\n", p / two_pow_n_min_one);
		// printf("%lld\n", (a[n - 1] * (p / two_pow_n_min_one)));

		// printf("%lld\n", ans);

		// for(int b = 0; b <= n - 1; b++){
		// 	if( (p >> b) & 1 ){
		// 		ans = ans + a[b];
		// 	}
		// }

		// cout << ans << " " << p << endl;

		int k;
		for(int j = 60; j >= 0; j--){
			if( (p >> j) & 1 ){
				k = j;
				break;
			}
		}
		ans = ans + f(n, a, p, k + 1);

		// k be largest set bit of p
		// int k;
		// for(int j = 60; j >= 0; j--){
		// 	if( (p_0 >> j) & 1 ){
		// 		k = j;
		// 		break;
		// 	}
		// }
		// if(k + 1 <= n - 1){
		// 	ans = lmin(ans, a[k + 1]);
		// }

		printf("%lld\n", ans);
	}

	return 0;
}