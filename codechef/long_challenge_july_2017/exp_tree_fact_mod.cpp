/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
vll dp_m1;
vll dp_m2;

ll fast_pow(ll b, ll e, ll m){
	if(e == 0)
		return 1;
	if(e == 1)
		return b % m;
	
	ll temp = fast_pow(b, e / 2, m);
	if(e % 2 == 0)
		return (temp * temp) % m;
	return ( ((temp * temp) % m) * (b % m) ) % m;
}

ll modulo_inverse(ll a, ll m){
	return fast_pow(a, m - 2, m);
}

void preprocess_factorial(vll &a, ll n, ll m){
	a[0] = 1;
	ll upper = (n < m - 1) ? n : m - 1;
	for(ll i = 1; i <= upper; i++){
		a[i] = (a[i - 1] * (i % m)) %m;
	}
}

ll get_catalan(ll n, vll& a, ll m){
	ll num, den;
	if(n >= m)
		num = 0;
	else
		num = a[2 * n];
	
	if(n >= m)
		den = 0;
	else
		den = (a[n + 1] * a[n]) % m;
	
	return (num * modulo_inverse(den, m)) % m;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const ll m1 = 1e9 + 7;
	const ll m2 = 1e9 + 9;

	const ll N = m2;
	dp_m1 = vll(N + 1, 0);
	dp_m2 = vll(N + 1, 0);
	preprocess_factorial(dp_m1, N, m1);
	preprocess_factorial(dp_m2, N, m2);

	ll t;
	cin >> t;

	ll n, p1, q1, p2, q2;
	while(t--){
		cin >> n;

		if(n == 1){
			p1 = p2 = 0;
			q1 = q2 = 1;
		}else{
			q1 = get_catalan(n - 1, dp_m1, m1);
			p1 = (get_catalan(n - 2, dp_m1, m1) * (n - 1) % m1) % m1;

			q2 = get_catalan(n - 1, dp_m2, m2);
			p2 = (get_catalan(n - 2, dp_m2, m2) * (n - 1) % m2) % m2;
		}

		cout << (p1 * modulo_inverse(q1, m1)) % m1;
		cout << " ";
		cout << (p2 * modulo_inverse(q2, m2)) % m2;
		cout << endl;
	}

	return 0;
}