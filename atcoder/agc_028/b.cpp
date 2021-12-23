#include <iostream>
#include <vector>
#define M 1000000007l
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

ll pow_mod_M(ll base, ll power){
	if(power == 0)
		return 1;
	else if((power & 1) == 0){
		ll h = power / 2;
		ll x = pow_mod_M(base, h);
		return (x * x) % M;
	}else{
		return (base * pow_mod_M(base, power - 1)) % M;
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	vll a = vll(n + 1);
	for(ll i = 1; i <= n; i++)
		cin >> a[i];

	ll fact_mod_m = 1;
	for(ll i = 1; i <= n; i++){
		fact_mod_m = (fact_mod_m * i) % M;
	}

	vll pi = vll(n + 1);
	for(ll i = 1; i <= n; i++){
		pi[i] = (fact_mod_m * pow_mod_M(i, M - 2)) % M;
	}

	vll prefix = vll(n + 1, 0);
	prefix[1] = pi[1];
	for(ll i = 2; i <= n; i++){
		prefix[i] = (prefix[i - 1] + pi[i]) % M;
	}

	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		ll delta = (a[i] * (prefix[i] + prefix[n - i + 1] - prefix[1] + M) % M) % M;
		ans = (ans + delta) % M;
	}

	cout << ans << endl;

	return 0;
}