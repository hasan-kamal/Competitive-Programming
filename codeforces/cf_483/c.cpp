/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

ll gcd(ll a, ll b){
	ll rem = a % b;
	if(rem == 0)
		return b;
	return gcd(b, rem);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, p, q, b;
	cin >> n;

	while(n--){
		cin >> p >> q >> b;
		if(p == 0){
			cout << "Finite" << endl;
			continue;
		}
		ll g = gcd(p, q);
		p = p / g;
		q = q / g;
		
		g = gcd(q, b);
		while(g != 1){
			q = q / g;
			g = gcd(q, g);
		}
		if(q > 1){
			cout << "Infinite" << endl;
		}else
			cout << "Finite" << endl;
	}

	return 0;
}