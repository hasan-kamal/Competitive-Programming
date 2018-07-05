/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cmath>
#define pb push_back
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll minimum(ll a, ll b){
	return a < b ? a : b;
}

ll cuberoot(ll x){
	ll lo = cbrt(x);
	ll hi = minimum(1e6 + 2, x);
	ll mid;

	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		if(mid * mid * mid >= x)
			hi = mid;
		else
			lo = mid + 1;
	}

	return lo;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	ll a, b;
	while(n--){
		cin >> a >> b;

		ll root = cuberoot(a * b);

		if( (a % root != 0) || (b % root != 0)){
			cout << "No" << endl;
			continue;
		}

		cout << "Yes" << endl;
	}		

	return 0;
}