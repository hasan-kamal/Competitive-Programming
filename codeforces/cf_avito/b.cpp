/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vll;

ll maximum(ll a, ll b){
	return a > b ? a : b;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vll seen;

	ll n;
	cin >> n;
	map<ll, ll> m1;
	ll a, x;
	while(n--){
		cin >> a >> x;
		m1[a] = x;
		seen.push_back(a);
	}

	ll m;
	cin >> m;
	map<ll, ll> m2;
	ll b, y;
	while(m--){
		cin >> b >> y;
		m2[b] = y;
		seen.push_back(b);
	}

	map<ll, bool> picked;
	ll ans = 0;
	for(ll elem : seen){
		if(picked.find(elem) != picked.end())
			continue;
		if(m1.find(elem) == m1.end())
			ans += m2[elem];
		else if(m2.find(elem) == m2.end())
			ans += m1[elem];
		else
			ans += maximum(m1[elem], m2[elem]);
		picked[elem] = true;
	}

	cout << ans;

	return 0;
}