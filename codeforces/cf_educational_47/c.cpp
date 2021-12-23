#include <iostream>
using namespace std;

typedef long long int ll;

ll beta(ll d, ll n){
	if(d > 0)
		return ( d * (n) * (n - 1) ) / 2;
	else if(d == 0)
		return 0;
	else{
		if(n % 2 == 0)
			return (d * n * n) / 4;
		else
			return (d * (n + 1) * (n - 1)) / 4;
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	ll xs = 0;
	ll bs = 0;

	ll x, d;
	for(int i = 0; i < m; i++){
		cin >> x >> d;
		xs += x;
		bs += beta(d, n);
	}

	double ans = xs + ((double)bs / (double)n);
	printf("%.15lf", ans);

	return 0;
}