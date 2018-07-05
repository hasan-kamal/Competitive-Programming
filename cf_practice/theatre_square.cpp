/*

@author Hasan Kamal

*/

#include <iostream>
using namespace std;

typedef long long int ll;

int main(){

	ll n, m, a;
	cin >> n >> m >> a;

	ll z;
	if(n % a == 0)
		z = n / a;
	else
		z = n / a + 1;

	ll y;
	if(m % a == 0)
		y = m / a;
	else
		y = m / a + 1;

	cout << y * z;

	return 0;
}