#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n = 20;
	ll a[20][20];

	for(ll i = 0; i< 20; i++)
		a[i][19] = 1;

	for(ll i = 0; i< 20; i++)
		a[19][i] = 1;	

	ll sum = 2 * 20;
	for(ll i = 18; i >= 0; i--){
		for(ll j = 18; j >= 0; j--){
			a[i][j] = a[i + 1][j] + a[i][j + 1];
			sum += a[i][j];
		}
	}

	for(ll i = 0; i < 20; i++)
		if(a[0][i] < 1e6){
			cout << i + 1 << endl;
			break;
		}
	cout << a[0][1] << endl;
	cout << a[1][0] << endl;
	cout << sum << endl;

	cout << a[0][3] << endl;

	return 0;
}