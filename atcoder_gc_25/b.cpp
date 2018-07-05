/*

@author hasankamal

*/

#include <iostream>
#include <climits>
#include <map>
using namespace std;
typedef long long int ll;

ll M = 998244353;

ll a, b;
map<ll, map<ll, ll> > p;
ll f(ll n, ll k){

	cout << n << " " << k << endl;
	if(n == 1){
		if(k == 0){
			return 1;
		}
		if(k == a){
			return 1;
		}
		if(k == b){
			return 1;
		}
		if(k == a + b){
			return 1;
		}

		return 0;
	}

	if(p[n].find(k) != p[n].end()){
		return p[n][k];
	}

	ll ans = ( f(n - 1, k - a) + f(n - 1, k - b) + f(n - 1, k - (a + b)) + f(n - 1, k) ) % M;
	p[n][k] = ans;
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> a >> b >> k;

	cout << f(n, k);
	
	return 0;
}