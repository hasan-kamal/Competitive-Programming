/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#define pb push_back
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll minimum(ll a, ll b){
	return a < b ? a : b;
}

ll cuberoot(ll x){
	ll lo = 1;
	ll hi = minimum(1e6 + 2, x);
	ll mid;

	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		if(mid * mid * mid >= x)
			hi = mid;
		else
			lo = mid + 1;
	}

	return lo;
}

int main(){

	ll n;
	scanf("%lld", &n);

	ll a, b;
	while(n--){

		scanf("%lld %lld", &a, &b);

		ll root = cuberoot(a * b);

		if( (a % root != 0) || (b % root != 0)){
			printf("No\n");
		}else{
			printf("Yes\n");
		}

	}		

	return 0;
}