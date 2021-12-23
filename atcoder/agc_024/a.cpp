/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

ll absol(ll x){
	return x < 0 ? -1 * x : x;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll ans;
	if(k % 2 == 0)
		ans = a - b;
	else
		ans = b - a;

	if(absol(ans) > ((ll)1e18) ){
		cout << "Unfair";
		return 0;
	}

	cout << ans;

	return 0;
}