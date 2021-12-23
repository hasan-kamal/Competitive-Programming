/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll x, y;
	cin >> x >> y;

	double a1 = y * log(x);
	double a2 = x * log(y);
	// cout << a1 << " " << a2 << endl;
	double tol = 1e-5;
	if(abs(a1 - a2) <= tol){
		cout << '=';
	}else if(a1 > a2){
		cout << '>';
	}else{
		cout << '<';
	}

	return 0;
}