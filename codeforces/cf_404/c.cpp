/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin>>n>>m;

	if(n<=m){
		cout<<n;
		return 0;
	}

	//case n>m now

	ll alpha;

	ll lo = 0;
	ll hi = 2000000000;
	ll mid;
	while(lo<hi){
		mid = lo + (hi-lo)/2;
		if(mid*(mid+1)>=2*(n-m))
			hi = mid;
		else
			lo = mid+1;
	}
	alpha = lo;

	cout<<m+alpha;

	// ll last_count = n-1;
	// int i=1;
	// while(last_count>0){

	// 	last_count = min(last_count +m, n) - (i+1);

	// 	i++;
	// }

	// cout<<i;

	return 0;
}