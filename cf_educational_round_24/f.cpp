/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

bool check(ll x, ll n){
	ll b = (x % 2 == 0) ? x / 2 : x / 2 + 1;
	ll non_b = (n - b) * (n - b - 1) / 2;
	if(b + non_b >= x)
		return true;
	else
		return false;
}

int main(){

	ll q, n;
	cin >> q;

	ll lo, hi, mid;
	while(q--){
		cin >> n;

		lo = n - 1; //is surely possible for a tree
		hi = 2 * (n - 1); //for edges more than this, not possible for sure as we cannot have more than n - 1 bridges in graph
		while(lo < hi){
			mid = lo + (hi - lo + 1) / 2;
			if(check(mid, n))
				lo = mid;
			else
				hi = mid - 1;
		}

		cout << lo << endl;
	}

	return 0;
}