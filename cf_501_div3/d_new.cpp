#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
ll minimum(ll a, ll b){
	return a < b ? a : b;
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k, s;
	cin >> n >> k >> s;

	if(s >= k && (s <= k * (n - 1)) ){
		cout << "YES" << endl;
		ll loc = 1;
		ll jump;
		while(k > 0){
			jump = minimum(s - k + 1, n - 1);
			k--;
			s -= jump;

			// set loc
			if(loc + jump <= n)
				loc = loc + jump;
			else
				loc = loc - jump;

			cout << loc << " ";
		}
	}else
		cout << "NO";

	return 0;
}