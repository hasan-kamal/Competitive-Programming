/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

#define M 1000000007

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll power(ll base, ll exp){
	if(exp == 0)
		return 1;
	else if(exp == 1)
		return base%M;

	ll temp = power(base, exp/2);

	if(exp % 2 == 0)
		return (temp * temp)%M;
	else
		return (base%M * ( temp * temp )%M ) %M;
}

int main(){

	int t, n;
	cin >> t;

	ll ans;
	while(t--){
		cin >> n;

		if(n % 2 == 0)
			ans = ( ( 3 * power(2, n / 2) )%M - 2 + M )%M;
		else
			ans = ( 2 * (power(2, n / 2 + 1) - 1 + M)%M )%M;

		cout << ans << endl;
	}

	return 0;
}