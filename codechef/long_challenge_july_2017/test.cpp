/*

@author Hasan Kamal

*/

#include <iostream>
using namespace std;

typedef long long int ll;

const ll m = 1e9 + 9;
ll pow(ll b, ll p){
	if(p == 0)
		return 1;
	else if(p == 1)
		return b % m;

	ll temp = pow(b, p / 2);
	if(p % 2 == 0)
		return ( temp * temp ) % m;
	else
		return ( (b % m) * (temp * temp) % m ) % m;
}

int main(){

	ll num, den;
	cin >> num >> den;
	cout << ((num % m) * pow(den, m - 2)) % m<< endl;

	return 0;
}