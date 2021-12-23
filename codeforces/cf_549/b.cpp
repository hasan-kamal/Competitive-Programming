#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef vector<ll> vll;

ll f(ll x){
	ll ans = 1;
	while(x){
		ans = ans * (x % 10);
		x /= 10;
	}
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	vll p_10(11);
	p_10[0] = 1;
	for(ll i = 1; i <= 10; i++){
		p_10[i] = p_10[i - 1] * 10;
	}

	ll ans = f(n);

	ll num = 0;
	vll dig;
	ll n_ = n;
	while(n_){
		dig.push_back(n_ % 10);
		num++;
		n_ /= 10;
	}

	// try for n = 1
	for(ll i = num - 1; i >= 0; i--){
		if(dig[i] == 0)
			continue;
		ll new_num = n;
		for(int j = 0; j <= i; j++){
			new_num -= (dig[j] * p_10[j]);
		}
		new_num += ( (dig[i] - 1) * p_10[i] + (p_10[i] - 1) );
		// cout << "::" << new_num << endl;
		ans = max(ans, f(new_num));
	}

	cout << ans;

	return 0;
}