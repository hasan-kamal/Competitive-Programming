#include <iostream>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b){
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
	return (a * b) / gcd(a, b);
}

int main(){

	int n, m;
	string s, t;
	cin >> n >> m;
	cin >> s;
	cin >> t;

	ll l = lcm(n, m);
	ll c = lcm(l / n, l / m);
	ll a = c / (l / n);
	ll b = c / (l / m);

	int i = 0;
	int j = 0;
	
	while(i < n && j < m){
		if(s[i] != t[j]){
			cout << -1 << endl;
			return 0;
		}
		i += a;
		j += b;
	}

	cout << l << endl;

	return 0;
}