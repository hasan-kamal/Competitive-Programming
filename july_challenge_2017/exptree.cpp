/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

ll fast_pow(ll base, ll exp, ll m){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base % m;

	ll temp = fast_pow(base, exp / 2, m);
	if(exp % 2 == 0)
		return ( temp * temp ) % m;
	else
		return ( (( temp * temp ) % m) * (base % m) ) % m ;
}

ll inverse_modulo(ll a, ll m){
	return fast_pow(a, m - 2, m);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const ll m1 = 1e9 + 7;
	const ll m2 = 1e9 + 9;

	ll t;
	cin >> t;

	ll n, p1, q1, p2, q2;
	while(t--){
		cin >> n;

		p1 = ( (n % m1) * ((n - 1) % m1) ) % m1;
		p1 = (p1 * ((n - 1) % m1) ) % m1;
		q1 = ( 2 * n - 2 ) % m1;
		q1 = ( q1 * ((2 * n - 3) % m1) ) % m1;


		p2 = ( (n % m2) * ((n - 1) % m2) ) % m2;
		p2 = (p2 * ((n - 1) % m2) ) % m2;
		q2 = ( 2 * n - 2 ) % m2;
		q2 = ( q2 * ((2 * n - 3) % m2) ) % m2;

		cout << (p1 * inverse_modulo(q1, m1)) % m1 << " ";
		cout << (p2 * inverse_modulo(q2, m2)) % m2 << endl;
	}

	return 0;
}