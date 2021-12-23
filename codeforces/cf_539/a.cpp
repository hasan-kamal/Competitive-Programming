#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll p(ll doll, ll n, ll v){
	ll s = v;
	// base
	if(doll < v){
		// refill doll units here
		if(n - 1 <= doll)
			return 1;
		else
			return 0;
	}
	ll t = 2;
	while(s + t <= doll){
		s += t;
		t++;
	}
	t--;
	if(t >= n - v)
		return 1;
	else
		return 0;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, v;
	cin >> n >> v;

	int lo = 1;
	int hi = n * (n + 1) * v / 2;
	int mid;
	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		// cout << mid << " " << p(mid, n, v) << endl;
		if(p(mid, n, v))
			hi = mid;
		else
			lo = mid + 1;
	}

	cout << lo;

	return 0;
}