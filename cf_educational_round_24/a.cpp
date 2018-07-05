/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main(){

	ll n, k;
	cin >> n >> k;

	ll d = n / (2 * (k + 1));
	ll c = k * d;
	ll w_d = n - (c + d);

	cout << d << " " << c << " " << w_d;
	
	return 0;
}