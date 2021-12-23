/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll k;
	cin >> k;

	string s;
	cin >> s;

	vi count = vi(10, 0);
	ll n = s.length();
	ll sum = 0;
	for(ll i = 0; i < n; i++){
		count[s[i] - '0']++;
		sum += (s[i] - '0');
	}

	ll ans = 0;
	ll val = 0;
	while(sum < k){
		if( sum + ((9 - val) * count[val]) >= k){

			if((k - sum) % (9 - val) == 0)
				ans += ((k - sum) / (9 - val));
			else
				ans += ((k - sum) / (9 - val) + 1);

			break;

		}else{
			sum += ((9 - val) * count[val]);
			ans += count[val];
		}

		val++;

	}

	cout << ans;

	return 0;
}