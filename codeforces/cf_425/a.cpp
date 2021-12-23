/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;

	ll m = n / k;
	if(m % 2 == 0)
		cout << "NO";
	else
		cout << "YES";

	return 0;
}