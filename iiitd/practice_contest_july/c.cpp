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
		return (temp * temp) % m;
	else
		return ( ((temp * temp) % m) * (base % m) ) % m;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const ll m = 1e9 + 7;

	ll t;
	cin >> t;

	ll n, ans, temp;
	while(t--){
		cin >> n;
		temp = ( (n * (n - 1)) % m + 2 ) % m;
		ans = ( fast_pow(2, n - 1, m) * (temp) ) % m;
		ans = (ans - 1 + m) % m;
		cout << ans << endl;
	}

	return 0;
}