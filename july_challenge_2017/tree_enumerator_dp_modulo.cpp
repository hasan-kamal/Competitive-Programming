/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
ll f(ll n);
ll num_vertices_one_child;
typedef vector<ll> vll;
typedef vector<vll> vvll;
vll dp_f;
vvll dp_g;
vll dp_num_one;

ll g(ll num_children, ll num_nodes){

	// if(num_nodes < 0 || num_children < 0){
	// 	cout << "negative overflow" << endl;
	// }

	// if(dp_g[num_children][num_nodes] >= 0)
	// 	return dp_g[num_children][num_nodes];

	if(num_nodes < num_children){
		dp_g[num_children][num_nodes] = 0;
		return 0;
	}

	if(num_children == 1){
		dp_g[num_children][num_nodes] = f(num_nodes) + 1;
		return dp_g[num_children][num_nodes];
	}

	ll ans = 0;
	for(ll i = 1; i <= num_nodes + 1 - num_children; i++)
		ans += ( f(i) * g(num_children - 1, num_nodes - i) );

	// if(ans != dp_g[num_children][num_nodes]){
	// 	cout << "dif " << num_children << " " << num_nodes << endl;
	// 	cout << "--- " << ans << " " << dp_g[num_children][num_nodes];
	// 	cout << endl;
	// }
	dp_g[num_children][num_nodes] = ans;

	return ans;

}

ll f(ll n){
	if(dp_f[n] > 0){
		num_vertices_one_child += dp_num_one[n];
		return dp_f[n];
	}

	if(n == 0 || n == 1){
		dp_f[n] = 1;
		dp_num_one[n] = 0;
		return 1;
	}

	ll num_children;
	ll ans = 0;
	for(num_children = 1; num_children <= n - 1; num_children++){

		ans += g(num_children, n - 1);
		if(num_children == 1)
			num_vertices_one_child += ans;

	}

	dp_f[n] = ans;
	dp_num_one[n] = num_vertices_one_child;

	return ans;
}

ll fast_pow(ll b, ll e, ll m){
	if(e == 0)
		return 1;
	if(e == 1)
		return b % m;
	ll temp = fast_pow(b, e / 2, m);
	
	if(e % 2 == 0)
		return (temp * temp) % m;
	else
		return ( ((temp * temp) % m) * (b % m) ) % m;
}

ll inverse(ll a, ll m){
	return fast_pow(a, m - 2, m);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	const ll m1 = 1e9 + 7;
	const ll m2 = 1e9 + 9;

	const ll N = 1e3;
	dp_g = vvll(N + 1, vll(N + 1, -1));
	dp_f = vll(N + 1, -1);
	dp_num_one = vll(N + 1, -1);

	ll n, p, q;
	for(ll i = 1; i <= t; i++){
		
		num_vertices_one_child = 0;
		q = f(i);
		p = num_vertices_one_child;
		
		// cout << "p=" << p << " q=" << q;
		// cout << " p.q-1(mod m1)=" << ((p % m1) * (inverse(q, m1) % m1)) % m1;
		// cout << " p.q-1(mod m2)=" << ((p % m2) * (inverse(q, m2) % m2)) % m2;
		// cout << endl;

		cout << ((p % m1) * (inverse(q, m1) % m1)) % m1;
		cout << " " << ((p % m2) * (inverse(q, m2) % m2)) % m2;
		cout << endl;
	}

	return 0;
}