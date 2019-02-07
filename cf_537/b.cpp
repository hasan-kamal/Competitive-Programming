#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll n, k, m;
vll a;
vll rsum;

ll mn(ll a, ll b){
	return a < b ? a : b;
}

ll f(ll start, ll num, ll m_){
	if(start == num){
		return start;
	}
	if(m_ == 0){
		return start;
	}
	double remove = ( rsum[n] - rsum[start] + mn(m_ - 1, (num - start) * k) ) / (double) (num - start);
	double keep = ( rsum[n] - rsum[start - 1] + mn(m_, (num - start + 1) * k) ) / (double) (num - start + 1);
	if(keep >= remove)
		return start;
	return f(start + 1, num, m_ - 1);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> m;

	a = vll(n + 1, 0);
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	rsum = vll(n + 1);
	rsum[0] = a[0];
	for(ll i = 1; i <= n; i++){
		rsum[i] = rsum[i - 1] + a[i];
	}

	ll take = f(1, n, m);

	double ans =  ( (rsum[n] - rsum[take - 1]) + mn(m - take + 1, (n - take + 1)* k)) / (double) (n - take + 1);
	printf("%.10f", ans);

	return 0;
}