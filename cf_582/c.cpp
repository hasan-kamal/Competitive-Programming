#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	ll n, m;
	while(q--){
		cin >> n >> m;
		ll l = 1, s = m % 10, i = 2;

		vll sum(2, 0);
		sum[1] = s;
		while( (i * m) % 10 != (m % 10) ){
			s += (i * m) % 10;
			sum.push_back(sum[sum.size() - 1] + (i * m) % 10);
			i++;
			l++;
		}

		ll alpha = n / m;
		// cout << endl;
		// cout << "alpha = " << alpha << endl;
		// cout << "s = " << s << endl;
		ll ans = s * (alpha / l) + sum[alpha % l];
		cout << ans << endl;
	}

	return 0;
}