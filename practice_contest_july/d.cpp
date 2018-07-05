/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
	return a * b / gcd(a, b);
}

ll lcm(ll a, ll b, ll c){
	return lcm(lcm(a, b), c);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	ll a, b, c;
	cin >> a >> b >> c;

	ll ans = 0;
	ans += n / a;
	ans += n / b;
	ans += n / c;
	ans -= n / lcm(a, b);
	ans -= n / lcm(b, c);
	ans -= n / lcm(a, c);
	ans += n / lcm(a, b, c);

	cout << ans;

	return 0;
}